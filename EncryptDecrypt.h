#ifndef __ENCRYPTDECRYPT_H__
#define __ENCRYPTDECRYPT_H__
#include <string>
#include "RSA.h"
class EncryptDecrypt {
public:
    EncryptDecrypt() {}
    ~EncryptDecrypt() {}

    void menu();    // 菜单显示
    bool encrypt();    // 加密
    bool decrypt();    // 解密
    void print();    // 打印RSA相关信息
    void reset();    // 重置RSA相关信息
    std::string stringToHex(std::string);
    int hexToInt(char c);
    std::string hexToString(std::string);
protected:
    void load(int);    // 根据给定位数加载RSA对象
    bool islegal(const std::string &);// 判断输入字符串是否合法
private:
    RSA rsa;
    std::string res;
};
#endif // __ENCRYPTDECRYPT_H__