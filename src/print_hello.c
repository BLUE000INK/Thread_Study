#include<stdio.h>
#include<stdlib.h>
#include<pthread.h>

//函数声明
void print_msg(void *ptr);

int main()
{
	//两个线程的标识
	int tmp1,tmp2;
	//任意性指针
	void *retval;
	//pthread_t 线程ID
	pthread_t thread1,thread2;
	char *msg1 = "thread1";
	char *msg2 = "thread2";
	
	//线程返回值
	int ret_thrd1,ret_thrd2;
	
	//phtread_creat :线程创建函数四个参数
	ret_thrd1 = pthread_create(&thread1,NULL,(void *)&print_msg,(void *)msg1);
	ret_thrd2 = pthread_create(&thread1,NULL,(void *)&print_msg,(void *)msg2);
	
	//线程创建成功，返回0，失败则返回失败号
	if(ret_thrd1 != 0){
		printf("线程1创建失败\n");
	}else{
		printf("线程1创建成功\n");
	}

	if(ret_thrd2 != 0){
		printf("线程2创建失败\n");
	}else{
		printf("线程2创建成功\n");
	}

	//同样， pthread_join成功返回值为0，失败则为失败号
	tmp1 = pthread_join(thread1,&retval);
	printf("thread1 return value(retval) is %d\n", (int) retval);
	printf("thread1 return value(tmp) is %d\n",tmp1);
	if(tmp1 != 0 ){
		printf("cannot join with thread1\n");
	}
	printf("thread1 end\n");


	 tmp2 = pthread_join(thread2,&retval);
	 printf("thread2 return value(retval) is %d\n", (int) retval);
	 printf("thread2 return value(tmp) is %d\n",tmp2);
	 if(tmp2 != 0 ){
		 printf("cannot join with thread2\n");
	 }
	 printf("thread2 end\n");
}
void print_msg(void *ptr){
	int i = 0;
	for(i;i<5;i++){
		printf("%s:%d\n",(char *)ptr,i);
	}
}
