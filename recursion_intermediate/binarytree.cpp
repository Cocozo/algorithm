#include<iostream>

using namespace std;

struct node
{
    int data;
    node *left;
    node *right;
};

void insert(node** root, int data);
void preOrder(node *root);
void inOrder(node *root);
void postOrder(node *root);
int size(node *root);
int height(node *root);
int sumOfWeight(node *root);
int maxPathWeight(node *root);
void mirror(node **root);

void destruct(node **root);
int main()
{

    int numTestCases;
    cin >> numTestCases;
    while (numTestCases--)
    {
        int num, i;
        node *root = NULL;
        scanf("%d", &num);
        for (i = 0; i < num; i++)
        {
            int data;
            cin >> data;
            insert(&root, data);
        }
        printf("%d\n", size(root));
        printf("%d\n", height(root));
        printf("%d\n", sumOfWeight(root));
        printf("%d\n", maxPathWeight(root));
        mirror(&root);
        preOrder(root);
        printf("\n");
        inOrder(root);
        printf("\n");
        postOrder(root);
        printf("\n");
        destruct(&root); // BST의 모든 노드의 동적 메모리 해제 
        if (root == NULL) printf("0\n");
        else printf("1\n");
    }
    return 0;
}
// 데이터 삽입(recursion)
void insert(node** root, int data)
{
    if(*root == NULL)
    {
        *root = new node;
        (*root)->data = data;
        (*root)->left = NULL;
        (*root)->right = NULL;
        //cout << (*root)->data << endl;
        return ;
    }

    if((*root)->data > data) insert(&((*root)->left), data);
    else insert(&((*root)->right), data);

}
// 전위(preorder)탐색(recursion) 

void preOrder(node* root) 
{
    if(root == NULL) return;
    cout << root->data << " ";
    preOrder(root->left);
    preOrder(root->right);
}

void inOrder(node *root)
{
    if (root == NULL) return;
    inOrder(root->left);
    cout << root->data << " ";
    inOrder(root->right);
}

// 후위(postorder)탐색(recursion) 
void postOrder(node* root)
{
    if (root == NULL) return;
    postOrder(root->left);
    postOrder(root->right);
    cout << root->data << " ";
}

// 노드의 개수(recursion) 
int size(node* root)
{
    if(root == NULL) return 0;
    int sum = 1;
    sum += size(root->left);
    sum += size(root->right);
    return sum;
}

// 높이(recursion)
int height(node *root)
{
    if(root == NULL) return 0;
    if(root->left == NULL && root->right == NULL) return 0;

    int leftHeight = height(root->left);
    int rightHeight = height(root->right);

    if(leftHeight <= rightHeight) return 1 + rightHeight;
    else return 1 + leftHeight;
}
// 미러 이미지로 변환하기(recursion) 
void mirror(struct node** root)
{
    if (*root == NULL) return;
    mirror(&((*root)->left));
    mirror(&((*root)->right));

    node *temp = (*root)->left;
    (*root)->left = (*root)->right;
    (*root)->right = temp;
}
// 노드에 저장된 데이터의 값의 합 구하기(recursion) 
int sumOfWeight(struct node* root)
{
    if(root == NULL) return 0;
    int sum = root->data;
    sum += sumOfWeight(root->left);
    sum += sumOfWeight(root->right);
    return sum;
}
// 루트노드부터 단말노드까지의 경로 상의 데이터의 최대합(recusrion) 
int maxPathWeight(struct node* root)
{
    if(root == NULL) return 0;

    int leftWeight = maxPathWeight(root->left);
    int rightWeight = maxPathWeight(root->right);

    if(leftWeight <= rightWeight) return root->data + rightWeight;
    else return root->data + leftWeight;
}

// 트리노드의 동적 메모리 해제하기(recursion) 
void destruct(struct node** root)
{
    if(*root == NULL) return;

    destruct(&((*root)->left));
    destruct(&((*root)->right));
    
    node *temp = *root;
    *root = NULL;
    delete temp;
}