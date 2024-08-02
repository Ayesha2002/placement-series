bool sortArr(int n, vector<int> &arr){
    vector<int> ans = arr ;
    sort(arr.begin(),arr.end()) ;
    int first_index=0 ;
    int second_index=0 ;
    for(int i=0;i<ans.size();i++){
        if(arr[i]!=ans[i]){
            first_index=i ;
            break ;
        }
    }
     for(int i=0;i<ans.size();i++){
        if(arr[i]!=ans[i]){
            second_index=i ;
            
        }
    }
   
    reverse(ans.begin()+first_index,ans.begin()+second_index+1) ;
    if(ans==arr) return true ;
 return false ;   
}
