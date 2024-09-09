class Solution {
public:
    vector<vector<int>> spiralMatrix(int m, int n, ListNode* head) {
      vector<vector<int>> ans(m, vector<int>(n,-1));

      int startRow=0;
      int startCol=0;
      int endRow=m-1;
      int endCol=n-1;
      

      ListNode* temp=head;

      while(temp!=NULL){
        //Traverse the top row.
        for(int i=startCol; i<=endCol && temp!=NULL; i++){
            ans[startRow][i]=temp->val;
            temp=temp->next;
          }
        startRow++;
        
        //Traverse the right column.
        for(int i=startRow; i<=endRow && temp!=NULL; i++){
            ans[i][endCol]=temp->val;
            temp=temp->next;
           }
        endCol--;
        
        //Traverse the bottom row.
        for(int i=endCol; i>=startCol && temp!=NULL; i--){
            ans[endRow][i]=temp->val;
            temp=temp->next;
           }
        endRow--;
        
        //Traverse the left column.
        for(int i=endRow; i>=startRow && temp!=NULL; i--){
            ans[i][startCol]= temp->val;
            temp=temp->next;
           }
        startCol++;

      }
        return ans;
    }
};
