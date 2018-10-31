#include "SSOGetAuthToken.h"

string SSOGetAuthToken::find_data = "";

SSOGetAuthToken::SSOGetAuthToken(int interval, int count)
{
    LOG_WARN("SSOGetAuthToken CREATE!!!");

    setInterval(interval);
    setCount(count);

    //CSSOTestUtil::SplitParam(params, ".", input_lists);
    //find_data = input_lists[0];

    setResultChecker(new CSSODataChecker());
}

SSORESULT SSOGetAuthToken::callApi()
{
    SSORESULT ret = sso_get_auth_token(&auth_token);

    string temp(auth_token);

    getResultChecker()->setDatas(temp);
    bool result_check = getResultChecker()->checkStringResult();

    if(result_check == true)
    {
        setSuccess();

        LOG_INFO("auth token is : [%s]", auth_token);        
        LOG_TIME("success count is [%d]", getSuccess());
    }
    else
    {
        setFail();

        LOG_INFO("no auth token");
        LOG_TIME("fail count is [%d]", getFail());
    }
    
    return ret;
}

