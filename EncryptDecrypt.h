#ifndef __ENCRYPTDECRYPT_H__
#define __ENCRYPTDECRYPT_H__
#include <string>
#include "RSA.h"
class EncryptDecrypt {
public:
    EncryptDecrypt() {}
    ~EncryptDecrypt() {}

    void menu();    // �˵���ʾ
    bool encrypt();    // ����
    bool decrypt();    // ����
    void print();    // ��ӡRSA�����Ϣ
    void reset();    // ����RSA�����Ϣ
    std::string stringToHex(std::string);
    int hexToInt(char c);
    std::string hexToString(std::string);
protected:
    void load(int);    // ���ݸ���λ������RSA����
    bool islegal(const std::string &);// �ж������ַ����Ƿ�Ϸ�
private:
    RSA rsa;
    std::string res;
};
#endif // __ENCRYPTDECRYPT_H__