// we have to convert a n*n   into a Linkedlist 2d format

//  in this type of question we have to think about the apporach of --struct what it given


// struct Node
// {
//     int data;
//     Node* right, *down;

//     Node(int x){
//         data = x;
//         right = NULL;
//         down = NULL;
//     }
// };
// */

// // function must return the pointer to the first element of the in linked list i.e. that
// // should be the element at arr[0][0]
// class Solution {
//   public:
//     Node* constructLinkedMatrix(vector<vector<int>>& mat) {
        
        
//     //using the code of thinking 
//     //bhai isme logic ye tha ki hum ek 2d linkedlist bnana chye
    
//     //check empty
    
//     if(mat.empty()|| mat[0].empty()) return nullptr;
    
//     int rows=mat.size();
//     int cols=mat[0].size();
    
    
//     Node* nodeMatrix[rows][cols];   // ye bta raah ki ek 2d matrix bna gya smje ye key point
    
    
//     for(int i=0;i<rows;i++)
//     {
//         for( int j=0;j<cols;j++)
//         {
//             nodeMatrix[i][j]=new Node(mat[i][j]);
//         }
//     }
    
//     //linking part
    
//     for(int i=0;i<rows;i++)
//     {
//         for(int j=0;j<cols;j++)
//         {
//             //link right
            
//             if(j+1< cols) nodeMatrix[i][j]->right=nodeMatrix[i][j+1];
            
//             //link down
            
//             if(i+1<rows)
//             {
//                 nodeMatrix[i][j]->down=nodeMatrix[i+1][j];
//             }
//         }
//     }
    
    
    
//     return nodeMatrix[0][0];
    
        
        
        
//     }

