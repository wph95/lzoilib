int ql,qr,v;//查询的左端点和右端点,修改参数
int _min,_max,_sum; //保存最小值、最大值、和的全局变量 

void update(int o,int L,int R);//将[ql,qr]增加v
void query(int o,int L,int R,int add);//查询[ql,qr],保存相关值至全局变量
void maintain(int o,int L,int R);//维护结点o,对应区间为[L,R] 
void set_update(int o,int L,int R);//设置[ql,qr]为v
void pushdown(int o);//下推set标记
void set_query(int o,int L,int R);//set版的查询


void update(int o,int L,int R){ 
  int lc=o*2,rc=o*2+1; 
  if(y1<=L && y2>=R){ 
    addv[o]+=v; 
  }else{ 
    int M=L+(R-L)/2; 
    if(y1<=M) update(lc,L,M); 
    if(y2>M)  update(rc,M+1,R); 
  } 
  maintain(o,L,R); 
}

void query(int o,int L,int R,int add){ 
  if(y1<=L && y2>=R){ 
    _sum+=sumv[o]+add*(R-L+1); 
    _min=min(_min,minv[o]+add); 
    _max=max(_max,maxv[o]+add); 
  }else{ 
    int M=L+(R-L)/2; 
    if(y1<=M) query(o*2,L,M,add+addv[o]); 
    if(Y2>M)  query(o*2+1,L,M,add+addv[o]); 
  } 
}


void maintain(int o,int L,int R){ 
  int lc=o*2,rc=o*2+1; 
  if(R>L){  //维护到叶子结点什么的就挂了 
    sumv[o]=sumv[lc]+sumv[rc]; 
    minv[o]=min(minv[lc],minv[rc]); 
    maxv[o]=max(maxv[lc],maxv[rc]); 
  } 
  minv[o]+=addv[o]; maxv[o]+=addv[o];  
  sumv[o]+=addv[o]*(R-L+1); 
}

void set_update(int o,int L,int R){ 
  int lc=o*2,rc=o*2+1; 
  if(y1<=L && y2>=R){ 
    setv[o]=v; 
  }else{ 
    pushdown(o); 
    int M=L+(R-L)/2; 
    if(y1<=M) set_update(lc,L,M);else maintain(lc,L,M); 
    if(y2>M)  set_update(rc,M+1,R);else maintain(rc,M+1,R); 
  } 
  maintain(o,L,R); 
}

void pushdown(int o){ 
  int lc=o*2,rc=o*2+1; 
  if(setv[o]>=0){    //该结点有标记的话 
    setv[lc]=setv[rc]=setv[o]; 
    setv[o]=-1;     //清除标记 
  } 
}

void set_query(int o,int L,int R){ 
  if(setv[o]>=0){ 
    _sum+=setv[o]*(min(R,y2)-max(L,y1)+1); 
    _min=min(_min,setv[o]); 
    _max=max(_max,setv[o]); 
  }else if(y1<=L && y2>=R){ 
    _sum+=sumv[o]; 
    _min= min(_min,minv[o]); 
    _max= max(_max,maxv[o]); 
}else{ 
  int M=L+(R-L)/2; 
  if(y1<=M) set_query(o*2,L,M); 
  if(y2> M) set_query(o*2,M+1,R); 
  } 
}
