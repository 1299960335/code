bool isLongPressedName(char * name, char * typed){
      if(name==NULL||typed==NULL)
      return false;
      int nam=strlen(name);
      int typ=strlen(typed);
      char temp;
      int idex=0;
      for(int i=0;i<typ;i++){
          if(name[idex]==typed[i]){
              idex++;
              temp=typed[i];
          }
          else if(temp==typed[i]){
              continue;
          }
          else{
              return false;
          }
      }
      return idex==nam;
}