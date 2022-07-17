#include <iostream>
#include "EncryptDecrypt.h"
int main() {
    EncryptDecrypt encrypt_decrypt;
    encrypt_decrypt.reset();// ������Կ����
    char ch;
    std::string str;
    bool ok = true;
    do {
        encrypt_decrypt.menu();// �˵���ʾ
        std::cout << ">";
        std::cin >> str;
        if (str.empty()) {
            std::cout << "�������!����������!" << std::endl;
            continue;
        }
        ch = str.at(0);
        switch(ch) {
        case 'e':
        case 'E':
            if (!encrypt_decrypt.encrypt())
                std::cout << "����ʧ��,������!" << std::endl;
            break;
        case 'd':
        case 'D':
            if (!encrypt_decrypt.decrypt())
                std::cout << "����ʧ��,������!" << std::endl;
            break;
        case 'p':
        case 'P':
            encrypt_decrypt.print();// ��ӡ�����Ϣ
            break;
        case 'r':
        case 'R':
            encrypt_decrypt.reset();// ����������Կ����
            break;
        case 'q':
        case 'Q':
            ok = false;    // �˳�
            break;
        default:
            break;
        }
    } while (ok);
    return 0;
}