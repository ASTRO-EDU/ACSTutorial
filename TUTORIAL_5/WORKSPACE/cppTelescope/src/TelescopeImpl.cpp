#include <TelescopeImpl.h>
 
TelescopeImpl::TelescopeImpl(const ACE_CString& name, maci::ContainerServices * containerServices) : ACSComponentImpl(name, containerServices) {
    this->x_pos = 0;
    this->y_pos = 0;
}
 
TelescopeImpl::~TelescopeImpl() {
}
 

void TelescopeImpl::moveTo(float x, float y) {
    
    if(x < 0) {
        throw CUSTOMErr::PositionOutOfLimitsExImpl(__FILE__, __LINE__, "moveTo(..) raises an Exception: x < 0").getPositionOutOfLimitsEx();
    }
    if(y < 0) {
        throw CUSTOMErr::PositionOutOfLimitsExImpl(__FILE__, __LINE__, "moveTo(..) raises an Exception: y < 0").getPositionOutOfLimitsEx();
    }

    this->x_pos = x;
    this->y_pos = y;
    
}  

char* TelescopeImpl::getCurrentPosition() {
    std::ostringstream ss;
    ss << "Current position: (" << this->x_pos << "," << this->y_pos << ")";
    std::string pos_str(ss.str());
    std::cout << pos_str << std::endl;
    return CORBA::string_dup(pos_str.c_str());
}

 
/* --------------- [ MACI DLL support functions ] -----------------*/
#include <maciACSComponentDefines.h>
MACI_DLL_SUPPORT_FUNCTIONS(TelescopeImpl)
/* ----------------------------------------------------------------*/