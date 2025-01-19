#include "NativeDnd.h"
#include <iostream>
#include <dlfcn.h> // Thư viện cho dynamic linking
// #include <CommApi.h> // Thư viện cho dynamic linking

namespace facebook::react {

NativeDnd::NativeDnd(std::shared_ptr<CallInvoker> jsInvoker)
    : NativeDndCxxSpec(std::move(jsInvoker)) {}

std::string NativeDnd::dndFun(jsi::Runtime& rt, std::string input) {
    const char* libPath = "libCommApi.so"; // Path to the .so file
    void* handle = dlopen(libPath, RTLD_LAZY);
    if (!handle) {
        std::string error = dlerror();
        return "Cannot open library: " + error;
    }

    // Example: Load a symbol (function) from the .so file
    using ProcessFunc = const char* (*)(const char*);
    ProcessFunc process = (ProcessFunc)dlsym(handle, "processInput");

    if (!process) {
        dlclose(handle);
        return "Cannot load symbol: " + std::string(dlerror());
    }

    // Call the function
    const char* result = process(input.c_str());

    // Clean up
    dlclose(handle);

    return std::string(result);

    // void* handle = dlopen("./libCommApi.so", RTLD_LAZY);
    // if (!handle) {
    //     return "Cannot open library: " + std::string(dlerror());
    // }
    // dlclose(handle);
    // void* handle = dlopen("libCommApi.so", RTLD_LAZY);
    // if (!handle) {
    //     return "_____Cannot open library00000: ";
    // }
        return "open library: ";

    // // Lấy địa chỉ hàm "getVersionStr"
    // typedef const char* (*getVersionStr_t)(); // Sửa kiểu trả về thành const char*
    // getVersionStr_t getVersionStr = (getVersionStr_t)dlsym(handle, "getVersionStr");
    // if (!getVersionStr) {
    //     std::cerr << "Cannot load symbol 'getVersionStr': " << dlerror() << std::endl;
    //     dlclose(handle);
    //     return "Cannot load symbol 'getVersionStr': " + std::string(dlerror());
    // }

    // // Gọi hàm
    // const char* version = getVersionStr();

    // // Đóng thư viện
    // dlclose(handle);

    // // Trả về chuỗi kết quả
    // return std::string(version);


    // Hsc3::Comm::CommApi cmApi.getVersionStr();
    
    //1.����ͨѶ�ͻ���
    // Hsc3::Comm::CommApi cmApi("./log/test");
    // //2.���÷��Զ�����ģʽ���˽ӿ�Ӧ��������ǰ���á�
    // cmApi.setAutoConn(false);
    // //3.���ӣ�������Ĭ������IP��"10.10.56.214"  - (std::string)���˿ں��ǹ̶�ֵ��23234 -��int��
    // Hsc3::Comm::HMCErrCode ret=cmApi.connect("127.0.0.1",23234);
    // if (ret!=0)
    // {
    //     printf("CommApi::connect :ret=%lld\n",ret);
    // }
    // //4.��ѯ�Ƿ�����,���Ӻ�ͨ���˽ӿ�ȷ������״̬��
    // if(cmApi.isConnected())
    // {
    //     std::cout<<"���ӳɹ�"<<std::endl;
    //     std::cout<<"�汾��Ϣ:"<<cmApi.getVersionStr()<<std::endl;  //��ȡ�汾��Ϣ��
    //     while(1)
    //     {
    //         std::string strCmd;
    //         std::cout<<"����������:"<<std::endl;
    //         std::cin>>strCmd;
    //         if (strCmd=="quit")
    //         {
    //             break;
    //         }
    //         else
    //         {
    //             std::string strRet;
    //             //ִ������ӿ�
    //             //��һ������:strCmd��������͸�ʽ��ͨ��ҵ���ӿ������ĵ���ѯ��
    //             //�ڶ�������������ִ�н��������һ��˫���Ű������ַ����������˽��ʱҪע���ַ����л���һ��˫���š�
    //             //�����������������ȼ�����ʹ���������ȼ�ö��ֵ��
    //             cmApi.execCmd(strCmd,strRet,Hsc3::Comm::PRIORITY_HIGH);
    //             std::cout<<strRet<<std::endl;
    //         }
    //     }
    // }
    // system("pause");
    // return "0";

}

} // namespace facebook::react
