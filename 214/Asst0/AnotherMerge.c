void merging(int left, int mid, int right) {
   int l, m, i;

   for(l = left, m = mid + 1, i = left; l <= mid && m <= right; i++) {
      if(list[l] <= list[m])
         temp[i] = list[l++];
      else
         temp[i] = list[m++];
   }
   
   while(l <= mid)    
      temp[i++] = list[l++];

   while(m <= right)   
      temp[i++] = list[m++];

   for(i = left; i <= right; i++)
      list[i] = temp[i];
}


