#ifndef DATABASE
#define DATABASE

#include <string>
#include <vector>

class Database {
public:
    std::vector<std::string> usernamesVector = { "user1", "user2", "user3" };
    std::vector<std::string> passwordsVector = { "user1pass", "user2pass", "user3pass" };

    std::string adminUsername = "admin";
    std::string adminPassword = "admin";

    std::vector<std::string> productNamesVector = { "knife1", "knife2", "knife3", "knife4", "knife5" };
    std::vector<float> productPricesVector = { 120.5f, 70.8f, 95.6f, 150.9f, 201.5f };
    std::vector<int> productQuantitiesVector = { 30, 30, 30, 30, 30 };

    std::vector<std::string> cartProductNamesVector;
    std::vector<float> cartProductPricesVector;
    std::vector<int> cartProductQuantitiesVector;
    std::vector<int> productIndexesVector;
    float totalPrice = 0;
};

#endif
