void inorder(Node* root, vector<int>&arr){
    if(root==NULL) return;
    
    inorder(root->left,arr);
    arr.push_back(root->data);
    inorder(root->right,arr);
    return;
}

float findMedian(struct Node *root)
{
    vector<int>arr;
      inorder(root,arr);
      int n=arr.size();
      float ans;
      if(n%2!=0){
          ans=arr[n/2];
      }
      else{ 
          ans=(arr[n/2]+arr[(n/2)-1])/2.0;
      }
      return ans;
}
