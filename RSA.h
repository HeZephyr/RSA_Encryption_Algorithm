#include <ostream>
#include "BigInteger.h"

class RSA {
public:
    RSA() {}
    RSA(const unsigned len) { init(len); }    // ����len��ʼ������
    ~RSA() {}

    void init(const unsigned);// ��ʼ��,������˽Կ��

    BigInteger encryptByPublic(const BigInteger &);    // ��Կ����
    BigInteger decryptByPrivate(const BigInteger &);// ˽Կ����

    // ������Ҫ��������ǩ��
    BigInteger encryptByPrivate(const BigInteger &);// ˽Կ����
    BigInteger decryptByPublic(const BigInteger &);    // ��Կ����
protected:
    friend std::ostream & operator << (std::ostream &, const RSA &);// ����������
private:
    BigInteger createOddNum(unsigned);// ����һ��������,����Ϊ�䳤��
    bool isPrime(const BigInteger &, const unsigned);// �ж��Ƿ�Ϊ����
    BigInteger createRandomSmaller(const BigInteger &);// �������һ����С����
    BigInteger createPrime(unsigned, const unsigned);// ����һ��������,����Ϊ�䳤��
    void createExponent(const BigInteger &);// �����ṩ��ŷ�������ɹ�Կ��˽Կָ��
public:
    BigInteger n, e;// ��Կ
private:
    BigInteger d;// ˽Կ
    BigInteger p, q;// ������p��q
    BigInteger eul;// n��ŷ������
};