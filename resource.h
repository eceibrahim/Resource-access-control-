#ifndef __RESOURCE_H__
#define __RESOURCE_H__ 


typedef enum 
{
	FREE  = 0  , 
	ALLOCATED 
}Resource_t  ; 

typedef enum 
{
	SUCCEED = 0 , 
	FAILED 
}AccessStatus_t ; 


AccessStatus_t AccessResource(Resource_t * resource , void (*function)(void * argument) , void * argument) ; 


#endif /*__RESOURCE_H__*/