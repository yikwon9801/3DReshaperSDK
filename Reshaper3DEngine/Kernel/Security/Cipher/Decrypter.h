#pragma once
#include "CipherTypes.h"

namespace Kernel
{
	namespace Security
	{
		namespace Cipher
		{

		/// this class uses Crypto++ lib (https://www.cryptopp.com/docs/ref/)
RsDEFINE_DLL_CLASS(Decrypter)
{

#pragma region Construction & Destruction

public:
	Decrypter(AuthenticatedEncryptionMode mode, BlockCipherAlgorithms algorithm);
	virtual ~Decrypter();

#pragma endregion

#pragma region Private Methods
private:

	
#pragma endregion

#pragma region Public Methods
public:
	string aes_decrypt_gcm(string strCipherText, string strKey, string strIV, string strTag);
	bool aes_decrypt_gcm(char* strCipherText, size_t length, string strKey, string strIV, string strTag, char** decryptText);
	bool aes_decrypt_gcm(string strCipherText, string strKey, string strIV, string strTag, string& decryptText);
	bool aes_decrypt_gcm_stream(istream& pEncryptedStream, string strKey, string strIV, string strTag, ostream& pDecryptedStream);
	string uncompress_string(char* pstrCompressed, size_t length);

#pragma endregion

#pragma region Memeber Variable
private:
	AuthenticatedEncryptionMode m_EncryptionMode;
	BlockCipherAlgorithms m_CipherAlgorithm;
#pragma endregion
};
		}
	}
}