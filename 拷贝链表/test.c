struct Node* copyRandomList(struct Node* head) {
	if(head==NULL){   //当指针为空的时候，直接返回空
        return NULL;
    }
    struct Node* cur=head;
    while(cur){   //创建拷贝节点，并将其放在原始节点的后面
     struct Node* copy=(struct Node*)malloc(sizeof(struct Node)); 
     copy->val=cur->val;
     copy->next=cur->next;
     cur->next=copy;
     cur=copy->next;  
    }
    cur=head;
    while(cur){ //拷贝节点random所指向的位置为原始节点random指向的位置的next
        struct Node* copy=NULL;
      copy=cur->next;
      if(cur->random){
          copy->random=cur->random->next;  
      }
      else{  //当原始节点指向空时，拷贝节点也指向空
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
    struct Node* copyHead=cur->next;//表示拷贝节点的头节点
    while(cur){  //将原始链表与拷贝链表分离，原始节点的next指向拷贝节点的next，
      struct Node* copy=cur->next;//拷贝节点的next指向next的next
      struct Node*next=copy->next;
      if(next!=NULL){
          cur->next=next;
          copy->next=next->next;
      } 
      else{//当next为空时，表示已经走到最后了，这时将两个链表的最后一个节点的next都指向空（next）
          cur=next;
          copy=next;
      }
    }
    return copyHead;//返回拷贝节点的头节点
}