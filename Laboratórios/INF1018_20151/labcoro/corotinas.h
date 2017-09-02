#define NO_PARAM 0

/* corpo de uma corotina */
typedef int (*FuncP)(int param);

/* referencia para uma corotina */
typedef struct coroutine *Coroutine; 

/* 
 * coro_create: cria uma nova corotina
 *
 * ParÃ¢metro: funÃ§Ã£o que implementa o "corpo" da corotina
 * Retorna: referencia para a corotina criada
 */
Coroutine coro_create(char *name, FuncP func);

/*
 * coro_resume: (re)ativa a execuÃ§Ã£o de uma corotina
 *
 * ParÃ¢metros:
 *   - referencia para a corotina a (re)ativar
 *   - parametro para a corotina (parametro inicial ou retorno do yield)
 *
 * Retorna:
 *   o parÃ¢metro passado a coro_yield quando a corotina suspender,
 *   ou o retorno do "corpo" da corotina, quando ela terminar
 */
int coro_resume(Coroutine coro, int param);

/*
 * coro_yield: suspende a execuÃ§Ã£o de uma corotina, retomando a execuÃ§Ã£o 
 *             do chamador 
 * ParÃ¢metros:
 *   - valor de retorno para o chamador (retorno do resume)
 *
 * Retorna:
 *   o parÃ¢metro passado a coro_resume quando a corotina for reativada
 */
int coro_yield(int param);

/*
 * coro_free: libera Ã¡rea usada por corotina
 *
 * ParÃ¢metro: referencia para a corotina
 */
void coro_free(Coroutine coro);

