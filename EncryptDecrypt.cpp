#include <iostream>
#include <sstream>
#include <ctime>
#include "EncryptDecrypt.h"

/**
 * ��������:�˵���ʾ
 */
void EncryptDecrypt::menu() {
    std::cout << "*************RSA�����㷨��ʾ����***************" << std::endl;
    std::cout << "               e: encrypt ����               " << std::endl;
    std::cout << "               d: decrypt ����               " << std::endl;
    std::cout << "               p: print   ��ʾ               " << std::endl;
    std::cout << "               r: reset   ����               " << std::endl;
    std::cout << "               q: quit    �˳�               " << std::endl;
    std::cout << "��������Ĳ���" << std::endl;
}

/**
 * ��������:��������
 */
bool EncryptDecrypt::encrypt() {
    std::string str;
    std::cout << "�������ļ���" << std::endl;
    std::cout << ">";
    std::getchar();
    std::getline(std::cin, str);// ��������
    if (!std::cin || !islegal(str))
        return false;
    res = str;
    BigInteger m(stringToHex(str));
    // ��������ʱ��
    clock_t start = clock();
    BigInteger c = rsa.encryptByPublic(m);
    clock_t finish = clock();

    std::cout << std::fixed;
    std::cout.precision(3);
    std::cout << "��ʱ: " << (double)(finish-start)/CLOCKS_PER_SEC << "s." << std::endl;
    // std::cout << "���ģ�ʮ�����ƣ���" << m << std::endl;
    std::cout << "����: " << hexToString(m.toHexString()) << std::endl;
    std::cout << "����: " << c << std::endl;
    return true;
}

/**
 * ��������:��������
 */
bool EncryptDecrypt::decrypt() {
    std::string str;
    std::cout << "�������Ľ���" << std::endl;
    std::cout << ">";
    std::cin >> str;// ��������
    if (!std::cin || !islegal(str)) // �ж��Ƿ����Ҫ�󣬼�ASCII����ֵ
        return false;
    BigInteger c(str);
    clock_t start = clock();
    BigInteger m = rsa.decryptByPrivate(c);
    clock_t finish = clock();

    std::cout << std::fixed;
    std::cout.precision(3);
    std::cout << "��ʱ: " << (double)(finish-start)/CLOCKS_PER_SEC << "s." << std::endl;
    std::cout << "����: " << c << std::endl;
    // std::cout << "���ģ�ʮ�����ƣ���" << m << std::endl;
    std::cout << "����: " << hexToString(m.toHexString()) << std::endl;
    return true;
}

/**
 * ��������:���RSA�����Ϣ
 */
void EncryptDecrypt::print() {
    std::cout << rsa << std::endl;
}

/**
 * ��������:����RSA�����Ϣ
 */
void EncryptDecrypt::reset() {
    std::cout << "������Կ����" << std::endl;
    std::cout << ">"; 
    int len;
    std::cin >> len;
    load(len>>1);
}

/**
 * ��������:���ݸ���λ��len����rsa
 */
void EncryptDecrypt::load(int len) {
    std::cout << "��ʼ��..." << std::endl;
    clock_t start = clock();
    rsa.init(len);    // ��ʼ��
    clock_t finish = clock();
    std::cout << "��ʼ�����." << std::endl;
    std::cout << std::fixed;
    std::cout.precision(3);
    std::cout << "��ʱ: " << (double)(finish-start)/CLOCKS_PER_SEC << "s." << std::endl;
}

/**
 * ��������:�ж������ַ���str�Ƿ�Ϸ�
 * ��������:str����������ַ���
 */
bool EncryptDecrypt::islegal(const std::string & str) {
    for (auto c : str) {
        if (c < 0 || c > 127) {
            return false;
        }
    }
    return true;
}
/**
 * ��������:�ַ���תʮ�������ַ���
 * ��������:strҪת����ʮ�����Ƶ��ַ���
 */
std::string EncryptDecrypt::stringToHex(std::string str)
{
	const std::string hex = "0123456789ABCDEF";
	std::stringstream ss;

	for (int i = 0; i < str.size(); ++ i) {
		ss << hex[(unsigned char)str[i] >> 4] << hex[(unsigned char)str[i] & 0xf];
    }
	return ss.str();
}
int EncryptDecrypt::hexToInt(char c) {
    if (c >= '0' && c <= '9') {
        return c - '0';
    }
    return c - 'A' + 10;
}
/**
 * ��������:ʮ�������ַ���תASCII�ַ���
 * ��������:strҪת����ASCII���ַ���
 */
std::string EncryptDecrypt::hexToString(std::string str) {
	const std::string hex = "0123456789ABCDEF";
	std::stringstream ss;

	for (int i = 0; i < str.size(); i += 2) {
		ss << char(hexToInt(str[i]) * 16 + hexToInt(str[i + 1]));
    }
	// return ss.str();
    return res;
}