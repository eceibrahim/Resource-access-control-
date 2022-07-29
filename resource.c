#include "resource.h" 

AccessStatus_t AccessResource(Resource_t * resource , void (*function)(void * argument) , void * argument) 
{
	AccessStatus_t status ; 
	
	DISABLE_INTERRUPTS ; 
	if(*resource == FREE)
	{
		*resource = ALLOCATED ; 
		ENABLE_INTERRUPTS ; 
		
		function(argument) ; 
		
		DISABLE_INTERRUPTS ; 
		*resource = FREE; 
		ENABLE_INTERRUPTS ; 
		
		status = SUCCEED ; 
	}
	else 
	{
		ENABLE_INTERRUPTS ; 
		
		status = FAILED; 
	}
	return status ; 
}