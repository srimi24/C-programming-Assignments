#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include<stdbool.h>
#define MAX 100

typedef struct node 
{
    int id; //ID of user
    int numfren; //number of friends of user
    char name[MAX]; //name of user
    int* friends; //friends of user as an array
    struct node* right;  //user to the right
    struct node* left; //user to the left
} node;

struct node* retUser(char str[MAX])
{
    char name[MAX];
    char ID[MAX];
    char strfriends[MAX];

    //copied ID
    char*token=strtok(str,",");
    strcpy(ID,token);

    //copied Name
    token=strtok(NULL,",");
    strcpy(name,token);

    //copied friends' ID
    token=strtok(NULL,",");
    strcpy(strfriends,token);
    //printf("%s\n",(strfriends));

    //creating user nodes
    int id=atoi(ID);
    struct node *user = malloc(sizeof(struct node));
    user->id=id;
    user->friends=(int*)malloc(MAX * sizeof(int));
    strcpy(user->name,name);


    //adding user's friend's IDs
    token = strtok(strfriends,"|");  
    int i=0;
    while( token != NULL ) 
    {

        int temp=atoi(token);
        user->friends[i]=temp;
        i++;
        token = strtok(NULL,"|");
    }
    user->numfren=i;
    if(i==0){user->friends[i]=-1;}
    
    return user;
}


//search for user with id=key
struct node* search(int key, struct node *users)
{
    //CODE HERE
    node *prev;
    node *cur;
    if(users == NULL)   
    {
        return NULL;
    }
    else
    {
        prev = NULL;
        cur = users;
        while(cur!=NULL)
        {
            prev = cur;
            if(key == cur->id)
            {
                return cur;
            }
            else if(key < cur->id)
            {
                cur = cur->left;
            }
            else
            {
                cur = cur->right;
            }
        }
        return NULL;
        
    }


}

//see document for explanattion
struct node*refineUser(struct node*user, struct node *users)
{
    //CODE HERE

    user->left = NULL;
    user->right = NULL;
    while(search(user->id,users) != NULL)
    {
        user->id ++;
    }

    
    for(int j = 0;j<user->numfren;j++)
    {
        struct node *matchednode = search(user->friends[j],users);
        if(matchednode != NULL)
        {
            matchednode->friends[matchednode->numfren] = user->id;
            matchednode->numfren++;
        }
    }
    
    return user;
   

}

//insert user with id
struct node* insertUser(struct node*root,int id,struct node*user)
{
   //CODE HERE
    {
    /* data */
    node *prev;
    node *cur;
    if(root == NULL)
    {
       root = user;
    }
    else
    {
        prev = NULL;
        cur = root;
        while(cur != NULL)
        {
            prev = cur;
            if(id < cur->id)
            {
                cur = cur -> left;
            }
            else
            {
                cur = cur->right;
            }
        }
        if(id < prev->id)
        {
            prev->left = user;
        }
        else
        {
            prev->right = user;
        }
        
    }
    
   }
   return root;
}

//prints friends list
void friends(int id, struct node *users) 
{
   //CODE HERE

   struct node *matchednode = search(id,users);
  
   if(matchednode->numfren == 0)
   {
    printf("-1\n");
   }
   else
   {
   int count = 0;
   for(int j=0;j<matchednode->numfren;j++)
   {
        if(search(matchednode->friends[j],users) != NULL)
        {
            printf("%d\n",matchednode->friends[j]);
        }
        else
        {
            count++;
        }
   }
   if(matchednode->numfren == count)
   {
    printf("-1\n");
   }
   }
}

//find child node with minimum value (inorder successor) - helper to delete node
struct node *minValueNode(struct node *node) {
  //CODE HERE
  struct node* cur = node;
  
    
    while (cur && cur->left != NULL)
        cur = cur->left;
  
    return cur;
}

//deletes itself from its friend's nodes
struct node*deleteFriends(int key, struct node*users)
{
    //CODE HERE
//    struct node* deletednode = search(key,users);
    struct node* deletednode = search(key,users);
    for ( int i=0;i<deletednode->numfren;i++)
    {
        struct node *searchednode = search(deletednode->friends[i],users);
        if(searchednode != NULL)
        {
            for( int j=0; j<searchednode->numfren; j++ ) {
                if(searchednode->friends[j] == deletednode->id)
                {
                    for( int k = j; k<searchednode->numfren-1; k++ )  {
                        searchednode->friends[k] = searchednode->friends[k+1];
                    }
                }
            }
        }

    }

    
}

// Deleting a node
struct node* deleteNode(struct node *root, int key) {
  //CODE HERE
    if (root == NULL)
        return root;
  
    else if (key < root->id)
        root->left = deleteNode(root->left, key);
  
    else if (key > root->id)
        root->right = deleteNode(root->right, key);
    else {
        if (root->left==NULL && root->right==NULL)  {
            free(root);
            return NULL;
        }
        else if (root->left == NULL) {
            struct node* temp = root->right;
            free(root);
            return temp;
        }
        else if (root->right == NULL) {
            struct node* temp = root->left;
            free(root);
            return temp;
        }
  
        struct node* temp = minValueNode(root->right);
  
        root->id = temp->id;

       
        root->numfren = temp->numfren;
        strcpy(root->name,temp->name);
        for(int i=0; i<root->numfren;i++){
            root->friends[i] = temp->friends[i];
        }

        root->right = deleteNode(root->right, temp->id);
    }
    return root;
}


//Print USER's IDs in ascending order
void printInOrder(node* myusers) 
{
    //CODE HERE
    if(myusers != NULL)
    {
        printInOrder(myusers->left);
        printf("%d %s\n",myusers->id,myusers->name);
        printInOrder(myusers->right);
    }
}


int main(int argc, char **argv)
{
    node *users=NULL;   
    while(1)
    {

        int opt, id;
        fflush(stdin);
        scanf("%d",&opt);
        char str[MAX];
        switch (opt)
        {
            case 1:
      
                scanf("%s",str);
                struct node*tbins=retUser(str);
                tbins=refineUser(tbins, users);
                users=insertUser(users,tbins->id,tbins);
               
                break;

            case 2:
           
                scanf("%d", &id);
                deleteFriends(id, users);
                users=deleteNode(users, id);
                break;

            case 3:
        
                scanf("%d", &id);
                node* result=search(id,users);
                if(result==NULL) 
                    printf("USER NOT IN TREE.\n");
                else{
                    printf("%d\n",result->id);
                }
                break;

            case 4:
                scanf("%d", &id);
                friends(id, users);
                break;

            case 5:
                printInOrder(users);
                break;

            case 6:
                exit(0);
                break;

            default: 
                printf("Wrong input! \n");
                break;
        }

    }
    return 0;
}