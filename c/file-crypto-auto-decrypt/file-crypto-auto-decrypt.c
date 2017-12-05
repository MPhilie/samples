/*
 * (c) 2017 Ionic Security Inc.
 * By using this code, I agree to the Terms & Conditions (https://www.ionic.com/terms-of-use/)
 * and the Privacy Policy (https://www.ionic.com/privacy-notice/).
 */

#include <iostream>
#include <ISAgent.h>
#include <ISFileCrypto.h>
#include <ISAgentSDKError.h>

int main()
{
	std::string inFilePath("example_file_encrypted.docx");
	std::string outFilePath("example_file_decrypted.docx");

	// Setup an agent object to talk to Ionic
    ionic_profile_persistor_t *profileLeaderOpt = ionic_profile_persistor_create_default();
    ionic_agent_t *agent = ionic_agent_create(profileLeaderOpt, NULL);

	//Encrypt the file using the classification
	ISFileCryptoCipherAuto cipher(agent);
	int nErrorCode = cipher.decrypt(inFilePath, outFilePath);

	// Validate the response
	if (nErrorCode != ISCRYPTO_OK) {
		std::cerr << "Error decrypting " << inFilePath << ": " << ISAgentSDKError::getErrorCodeString(nErrorCode) << std::endl;
		std::cout << "Press return to exit.";
		std::getchar();
		return -2;
	}

	std::cout << "Decrypted file " << inFilePath << " to " << outFilePath << "." << std::endl;
	std::cout << "Press return to exit.";
	std::getchar();
	return 0;
}