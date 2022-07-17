#include <iostream>
#include <sstream>
#include <ctime>
#include "EncryptDecrypt.h"

/**
 * 函数功能:菜单显示
 */
void EncryptDecrypt::menu() {
    std::cout << "*************RSA加密算法演示程序***************" << std::endl;
    std::cout << "               e: encrypt 加密               " << std::endl;
    std::cout << "               d: decrypt 解密               " << std::endl;
    std::cout << "               p: print   显示               " << std::endl;
    std::cout << "               r: reset   重置               " << std::endl;
    std::cout << "               q: quit    退出               " << std::endl;
    std::cout << "请输入你的操作" << std::endl;
}

/**
 * 函数功能:加密运算
 */
bool EncryptDecrypt::encrypt() {
    std::string str;
    std::cout << "输入明文加密" << std::endl;
    std::cout << ">";
    std::getchar();
    std::getline(std::cin, str);// 输入明文
    if (!std::cin || !islegal(str))
        return false;
    res = str;
    BigInteger m(stringToHex(str));
    // 计算所需时间
    clock_t start = clock();
    BigInteger c = rsa.encryptByPublic(m);
    clock_t finish = clock();

    std::cout << std::fixed;
    std::cout.precision(3);
    std::cout << "用时: " << (double)(finish-start)/CLOCKS_PER_SEC << "s." << std::endl;
    // std::cout << "明文（十六进制）：" << m << std::endl;
    std::cout << "明文: " << hexToString(m.toHexString()) << std::endl;
    std::cout << "密文: " << c << std::endl;
    return true;
}

/**
 * 函数功能:解密运算
 */
bool EncryptDecrypt::decrypt() {
    std::string str;
    std::cout << "输入密文解密" << std::endl;
    std::cout << ">";
    std::cin >> str;// 输入密文
    if (!std::cin || !islegal(str)) // 判断是否符合要求，即ASCII码数值
        return false;
    BigInteger c(str);
    clock_t start = clock();
    BigInteger m = rsa.decryptByPrivate(c);
    clock_t finish = clock();

    std::cout << std::fixed;
    std::cout.precision(3);
    std::cout << "用时: " << (double)(finish-start)/CLOCKS_PER_SEC << "s." << std::endl;
    std::cout << "密文: " << c << std::endl;
    // std::cout << "明文（十六进制）：" << m << std::endl;
    std::cout << "明文: " << hexToString(m.toHexString()) << std::endl;
    return true;
}

/**
 * 函数功能:输出RSA相关信息
 */
void EncryptDecrypt::print() {
    std::cout << rsa << std::endl;
}

/**
 * 函数功能:重置RSA相关信息
 */
void EncryptDecrypt::reset() {
    std::cout << "输入密钥长度" << std::endl;
    std::cout << ">"; 
    int len;
    std::cin >> len;
    load(len>>1);
}

/**
 * 函数功能:根据给定位数len加载rsa
 */
void EncryptDecrypt::load(int len) {
    std::cout << "初始化..." << std::endl;
    clock_t start = clock();
    rsa.init(len);    // 初始化
    clock_t finish = clock();
    std::cout << "初始化完成." << std::endl;
    std::cout << std::fixed;
    std::cout.precision(3);
    std::cout << "用时: " << (double)(finish-start)/CLOCKS_PER_SEC << "s." << std::endl;
}

/**
 * 函数功能:判断输入字符串str是否合法
 * 参数含义:str代表输入的字符串
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
 * 函数功能:字符串转十六进制字符串
 * 参数含义:str要转换成十六进制的字符串
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
 * 函数功能:十六进制字符串转ASCII字符串
 * 参数含义:str要转换成ASCII的字符串
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