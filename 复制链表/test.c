struct Node* copyRandomList(struct Node* head) {
	if(head==NULL){
        return NULL;
    }
    struct Node* cur=head;
    while(cur){
     struct Node* copy=(struct Node*)malloc(sizeof(struct Node)); 
     copy->val=cur->val;
     copy->next=cur->next;
     cur->next=copy;
     cur=copy->next;  
    }
    cur=head;
    while(cur){
        struct Node* copy=NULL;
      copy=cur->next;
      if(cur->random){
          copy->random=cur->random->next;  
      }
      else{
          copy->random=NULL;
      }
      cur=copy->next;
      if(cur!=NULL){
          copy=cur->next;
      }
      else
      copy=NULL;
    }
    cur=head;
    struct Node* copyHead=cur->next;
    while(cur){
      struct Node* copy=cur->next;
      struct Node*next=copy->next;
      if(next!=NULL){
          cur->next=next;
          copy->next=next->next;
      } 
      else{
          cur=next;
          copy=next;
      }
    }
    return copyHead;
}