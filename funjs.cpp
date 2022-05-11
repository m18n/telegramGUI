#include"include/funjs.h"
VServClient* funjs::viewsc = NULL;
void funjs::RegistrFunVServClient(VServClient* vs) {
    viewsc = vs;
  
}