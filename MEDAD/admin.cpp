#include "admin.h"
#include "allusers.h"


Admin::Admin() {}
Admin::~Admin() {}


void Admin::virtualfunc()
{

}

QString Admin::getBadgeNum() const{ return authorizedViewPassNum; }
