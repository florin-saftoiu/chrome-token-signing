/* Chrome Linux plugin
*
* This software is released under either the GNU Library General Public
* License (see LICENSE.LGPL) or the BSD License (see LICENSE.BSD).
*
* Note that the only valid version of the LGPL license as far as this
* project is concerned is the original GNU Library General Public License
* Version 2.1, February 1999
*/

#include "gmock/gmock.h"
#include "PKCS11CardManager.h"
#include "DateUtils.h"
#include "BinaryUtils.h"

using namespace testing;
using namespace std;

TEST(PKCS11CardManagerTest, getPersonalCode) {
  CK_TOKEN_INFO tokenInfo;
  PKCS11CardManager manager(&tokenInfo, "3082049030820378A00302010202103D1FE64FC8C737D44F83D8516448A1C0300D06092A864886F70D0101050500306C310B300906035504061302454531223020060355040A0C19415320536572746966697473656572696D69736B65736B7573311F301D06035504030C1654455354206F66204553544549442D534B20323031313118301606092A864886F70D0109011609706B6940736B2E6565301E170D3132303431303036353035365A170D3137303333313230353935395A30819A310B3009060355040613024545310F300D060355040A0C06455354454944311A3018060355040B0C116469676974616C207369676E61747572653124302206035504030C1BC5BD41494B4F56534B492C49474F522C33373130313031303032313113301106035504040C0AC5BD41494B4F56534B49310D300B060355042A0C0449474F52311430120603550405130B33373130313031303032313081A0300D06092A864886F70D010101050003818E0030818A02818100B10DDD16CF6A1766422EECCAC4A503A1574E230861684F85AC64FCA4C1D6FDDB80A99EADAC53012B3DD7CC8C67AE0F5D6230F501FD54433E0A7586303AC50B2E1BB193A8BA9E3E6432D48AF69573DF03C63DA85EB2320915E652436588C0DE9E869FE59F1D7313C8E6B2881CE32879CDACF49764D1A697ED4BCF221429ABA8B3020400D4F075A38201803082017C30090603551D1304023000300E0603551D0F0101FF0404030206403081990603551D2004819130818E30818B060A2B06010401CE1F030101307D305806082B06010505070202304C1E4A00410069006E0075006C0074002000740065007300740069006D006900730065006B0073002E0020004F006E006C007900200066006F0072002000740065007300740069006E0067002E302106082B060105050702011615687474703A2F2F7777772E736B2E65652F6370732F30220603551D11041B3019811769676F722E7A61696B6F76736B694065657374692E6565301D0603551D0E0416041494F72921E471EA01140CAC145348790E81052904301806082B06010505070103040C300A3008060604008E460101301F0603551D2304183016801441B6FEC5B1B1B453138CFAFA62D0346D6D22340A30450603551D1F043E303C303AA038A0368634687474703A2F2F7777772E736B2E65652F7265706F7369746F72792F63726C732F746573745F657374656964323031312E63726C300D06092A864886F70D01010505000382010100BF607220FD9FBF806DD2D3190BEB0549A2988C39F8086E50C10D6345B3CCA878E8EABD9152AB4D06CA66A56EBDBA69B5B378A42DCEDBD73CEED47E4A59789B982D743395A58A71CDCEE21EAC050561A15DB8CE16D465A73FB32C91FA680383ADFA95E48515C84A3A6D05A6A4A7EB7DB5DB68D76F5CD7E238C866A2BF7FA5269FA2277BA8C716F20DA1A147D2A79677FE1F8CDFAEA856FADCA99988C8EF1BC381D62F540B5196F6EFD45CD0EBB2F52DE8B8CF69F33EFE70C894BD40A634ABA3A9F5792EDC3A73003335BC7C7FF7F8F429A08138C57B62E2E306AF6E74213232691E0117FC646CEAEDEE1177C5807795A0599A540E654ECD31122D9B1FE248B004");
  ASSERT_EQ("37101010021", manager.getPersonalCode());
}

TEST(PKCS11CardManagerTest, getName) {
  CK_TOKEN_INFO tokenInfo;
  PKCS11CardManager manager(&tokenInfo, "3082049030820378A00302010202103D1FE64FC8C737D44F83D8516448A1C0300D06092A864886F70D0101050500306C310B300906035504061302454531223020060355040A0C19415320536572746966697473656572696D69736B65736B7573311F301D06035504030C1654455354206F66204553544549442D534B20323031313118301606092A864886F70D0109011609706B6940736B2E6565301E170D3132303431303036353035365A170D3137303333313230353935395A30819A310B3009060355040613024545310F300D060355040A0C06455354454944311A3018060355040B0C116469676974616C207369676E61747572653124302206035504030C1BC5BD41494B4F56534B492C49474F522C33373130313031303032313113301106035504040C0AC5BD41494B4F56534B49310D300B060355042A0C0449474F52311430120603550405130B33373130313031303032313081A0300D06092A864886F70D010101050003818E0030818A02818100B10DDD16CF6A1766422EECCAC4A503A1574E230861684F85AC64FCA4C1D6FDDB80A99EADAC53012B3DD7CC8C67AE0F5D6230F501FD54433E0A7586303AC50B2E1BB193A8BA9E3E6432D48AF69573DF03C63DA85EB2320915E652436588C0DE9E869FE59F1D7313C8E6B2881CE32879CDACF49764D1A697ED4BCF221429ABA8B3020400D4F075A38201803082017C30090603551D1304023000300E0603551D0F0101FF0404030206403081990603551D2004819130818E30818B060A2B06010401CE1F030101307D305806082B06010505070202304C1E4A00410069006E0075006C0074002000740065007300740069006D006900730065006B0073002E0020004F006E006C007900200066006F0072002000740065007300740069006E0067002E302106082B060105050702011615687474703A2F2F7777772E736B2E65652F6370732F30220603551D11041B3019811769676F722E7A61696B6F76736B694065657374692E6565301D0603551D0E0416041494F72921E471EA01140CAC145348790E81052904301806082B06010505070103040C300A3008060604008E460101301F0603551D2304183016801441B6FEC5B1B1B453138CFAFA62D0346D6D22340A30450603551D1F043E303C303AA038A0368634687474703A2F2F7777772E736B2E65652F7265706F7369746F72792F63726C732F746573745F657374656964323031312E63726C300D06092A864886F70D01010505000382010100BF607220FD9FBF806DD2D3190BEB0549A2988C39F8086E50C10D6345B3CCA878E8EABD9152AB4D06CA66A56EBDBA69B5B378A42DCEDBD73CEED47E4A59789B982D743395A58A71CDCEE21EAC050561A15DB8CE16D465A73FB32C91FA680383ADFA95E48515C84A3A6D05A6A4A7EB7DB5DB68D76F5CD7E238C866A2BF7FA5269FA2277BA8C716F20DA1A147D2A79677FE1F8CDFAEA856FADCA99988C8EF1BC381D62F540B5196F6EFD45CD0EBB2F52DE8B8CF69F33EFE70C894BD40A634ABA3A9F5792EDC3A73003335BC7C7FF7F8F429A08138C57B62E2E306AF6E74213232691E0117FC646CEAEDEE1177C5807795A0599A540E654ECD31122D9B1FE248B004");
  ASSERT_EQ("IGOR ŽAIKOVSKI", manager.getCardName());
}

TEST(PKCS11CardManagerTest, getSubjectCN) {
  CK_TOKEN_INFO tokenInfo;
  PKCS11CardManager manager(&tokenInfo, "3082049030820378A00302010202103D1FE64FC8C737D44F83D8516448A1C0300D06092A864886F70D0101050500306C310B300906035504061302454531223020060355040A0C19415320536572746966697473656572696D69736B65736B7573311F301D06035504030C1654455354206F66204553544549442D534B20323031313118301606092A864886F70D0109011609706B6940736B2E6565301E170D3132303431303036353035365A170D3137303333313230353935395A30819A310B3009060355040613024545310F300D060355040A0C06455354454944311A3018060355040B0C116469676974616C207369676E61747572653124302206035504030C1BC5BD41494B4F56534B492C49474F522C33373130313031303032313113301106035504040C0AC5BD41494B4F56534B49310D300B060355042A0C0449474F52311430120603550405130B33373130313031303032313081A0300D06092A864886F70D010101050003818E0030818A02818100B10DDD16CF6A1766422EECCAC4A503A1574E230861684F85AC64FCA4C1D6FDDB80A99EADAC53012B3DD7CC8C67AE0F5D6230F501FD54433E0A7586303AC50B2E1BB193A8BA9E3E6432D48AF69573DF03C63DA85EB2320915E652436588C0DE9E869FE59F1D7313C8E6B2881CE32879CDACF49764D1A697ED4BCF221429ABA8B3020400D4F075A38201803082017C30090603551D1304023000300E0603551D0F0101FF0404030206403081990603551D2004819130818E30818B060A2B06010401CE1F030101307D305806082B06010505070202304C1E4A00410069006E0075006C0074002000740065007300740069006D006900730065006B0073002E0020004F006E006C007900200066006F0072002000740065007300740069006E0067002E302106082B060105050702011615687474703A2F2F7777772E736B2E65652F6370732F30220603551D11041B3019811769676F722E7A61696B6F76736B694065657374692E6565301D0603551D0E0416041494F72921E471EA01140CAC145348790E81052904301806082B06010505070103040C300A3008060604008E460101301F0603551D2304183016801441B6FEC5B1B1B453138CFAFA62D0346D6D22340A30450603551D1F043E303C303AA038A0368634687474703A2F2F7777772E736B2E65652F7265706F7369746F72792F63726C732F746573745F657374656964323031312E63726C300D06092A864886F70D01010505000382010100BF607220FD9FBF806DD2D3190BEB0549A2988C39F8086E50C10D6345B3CCA878E8EABD9152AB4D06CA66A56EBDBA69B5B378A42DCEDBD73CEED47E4A59789B982D743395A58A71CDCEE21EAC050561A15DB8CE16D465A73FB32C91FA680383ADFA95E48515C84A3A6D05A6A4A7EB7DB5DB68D76F5CD7E238C866A2BF7FA5269FA2277BA8C716F20DA1A147D2A79677FE1F8CDFAEA856FADCA99988C8EF1BC381D62F540B5196F6EFD45CD0EBB2F52DE8B8CF69F33EFE70C894BD40A634ABA3A9F5792EDC3A73003335BC7C7FF7F8F429A08138C57B62E2E306AF6E74213232691E0117FC646CEAEDEE1177C5807795A0599A540E654ECD31122D9B1FE248B004");
  ASSERT_EQ("ŽAIKOVSKI,IGOR,37101010021", manager.getCN());
}

TEST(PKCS11CardManagerTest, getType) {
  CK_TOKEN_INFO tokenInfo;
  PKCS11CardManager manager(&tokenInfo, "3082049030820378A00302010202103D1FE64FC8C737D44F83D8516448A1C0300D06092A864886F70D0101050500306C310B300906035504061302454531223020060355040A0C19415320536572746966697473656572696D69736B65736B7573311F301D06035504030C1654455354206F66204553544549442D534B20323031313118301606092A864886F70D0109011609706B6940736B2E6565301E170D3132303431303036353035365A170D3137303333313230353935395A30819A310B3009060355040613024545310F300D060355040A0C06455354454944311A3018060355040B0C116469676974616C207369676E61747572653124302206035504030C1BC5BD41494B4F56534B492C49474F522C33373130313031303032313113301106035504040C0AC5BD41494B4F56534B49310D300B060355042A0C0449474F52311430120603550405130B33373130313031303032313081A0300D06092A864886F70D010101050003818E0030818A02818100B10DDD16CF6A1766422EECCAC4A503A1574E230861684F85AC64FCA4C1D6FDDB80A99EADAC53012B3DD7CC8C67AE0F5D6230F501FD54433E0A7586303AC50B2E1BB193A8BA9E3E6432D48AF69573DF03C63DA85EB2320915E652436588C0DE9E869FE59F1D7313C8E6B2881CE32879CDACF49764D1A697ED4BCF221429ABA8B3020400D4F075A38201803082017C30090603551D1304023000300E0603551D0F0101FF0404030206403081990603551D2004819130818E30818B060A2B06010401CE1F030101307D305806082B06010505070202304C1E4A00410069006E0075006C0074002000740065007300740069006D006900730065006B0073002E0020004F006E006C007900200066006F0072002000740065007300740069006E0067002E302106082B060105050702011615687474703A2F2F7777772E736B2E65652F6370732F30220603551D11041B3019811769676F722E7A61696B6F76736B694065657374692E6565301D0603551D0E0416041494F72921E471EA01140CAC145348790E81052904301806082B06010505070103040C300A3008060604008E460101301F0603551D2304183016801441B6FEC5B1B1B453138CFAFA62D0346D6D22340A30450603551D1F043E303C303AA038A0368634687474703A2F2F7777772E736B2E65652F7265706F7369746F72792F63726C732F746573745F657374656964323031312E63726C300D06092A864886F70D01010505000382010100BF607220FD9FBF806DD2D3190BEB0549A2988C39F8086E50C10D6345B3CCA878E8EABD9152AB4D06CA66A56EBDBA69B5B378A42DCEDBD73CEED47E4A59789B982D743395A58A71CDCEE21EAC050561A15DB8CE16D465A73FB32C91FA680383ADFA95E48515C84A3A6D05A6A4A7EB7DB5DB68D76F5CD7E238C866A2BF7FA5269FA2277BA8C716F20DA1A147D2A79677FE1F8CDFAEA856FADCA99988C8EF1BC381D62F540B5196F6EFD45CD0EBB2F52DE8B8CF69F33EFE70C894BD40A634ABA3A9F5792EDC3A73003335BC7C7FF7F8F429A08138C57B62E2E306AF6E74213232691E0117FC646CEAEDEE1177C5807795A0599A540E654ECD31122D9B1FE248B004");
  ASSERT_EQ("ESTEID", manager.getType());
}

TEST(PKCS11CardManagerTest, getIssuerCN) {
  CK_TOKEN_INFO tokenInfo;
  PKCS11CardManager manager(&tokenInfo, "3082049030820378A00302010202103D1FE64FC8C737D44F83D8516448A1C0300D06092A864886F70D0101050500306C310B300906035504061302454531223020060355040A0C19415320536572746966697473656572696D69736B65736B7573311F301D06035504030C1654455354206F66204553544549442D534B20323031313118301606092A864886F70D0109011609706B6940736B2E6565301E170D3132303431303036353035365A170D3137303333313230353935395A30819A310B3009060355040613024545310F300D060355040A0C06455354454944311A3018060355040B0C116469676974616C207369676E61747572653124302206035504030C1BC5BD41494B4F56534B492C49474F522C33373130313031303032313113301106035504040C0AC5BD41494B4F56534B49310D300B060355042A0C0449474F52311430120603550405130B33373130313031303032313081A0300D06092A864886F70D010101050003818E0030818A02818100B10DDD16CF6A1766422EECCAC4A503A1574E230861684F85AC64FCA4C1D6FDDB80A99EADAC53012B3DD7CC8C67AE0F5D6230F501FD54433E0A7586303AC50B2E1BB193A8BA9E3E6432D48AF69573DF03C63DA85EB2320915E652436588C0DE9E869FE59F1D7313C8E6B2881CE32879CDACF49764D1A697ED4BCF221429ABA8B3020400D4F075A38201803082017C30090603551D1304023000300E0603551D0F0101FF0404030206403081990603551D2004819130818E30818B060A2B06010401CE1F030101307D305806082B06010505070202304C1E4A00410069006E0075006C0074002000740065007300740069006D006900730065006B0073002E0020004F006E006C007900200066006F0072002000740065007300740069006E0067002E302106082B060105050702011615687474703A2F2F7777772E736B2E65652F6370732F30220603551D11041B3019811769676F722E7A61696B6F76736B694065657374692E6565301D0603551D0E0416041494F72921E471EA01140CAC145348790E81052904301806082B06010505070103040C300A3008060604008E460101301F0603551D2304183016801441B6FEC5B1B1B453138CFAFA62D0346D6D22340A30450603551D1F043E303C303AA038A0368634687474703A2F2F7777772E736B2E65652F7265706F7369746F72792F63726C732F746573745F657374656964323031312E63726C300D06092A864886F70D01010505000382010100BF607220FD9FBF806DD2D3190BEB0549A2988C39F8086E50C10D6345B3CCA878E8EABD9152AB4D06CA66A56EBDBA69B5B378A42DCEDBD73CEED47E4A59789B982D743395A58A71CDCEE21EAC050561A15DB8CE16D465A73FB32C91FA680383ADFA95E48515C84A3A6D05A6A4A7EB7DB5DB68D76F5CD7E238C866A2BF7FA5269FA2277BA8C716F20DA1A147D2A79677FE1F8CDFAEA856FADCA99988C8EF1BC381D62F540B5196F6EFD45CD0EBB2F52DE8B8CF69F33EFE70C894BD40A634ABA3A9F5792EDC3A73003335BC7C7FF7F8F429A08138C57B62E2E306AF6E74213232691E0117FC646CEAEDEE1177C5807795A0599A540E654ECD31122D9B1FE248B004");
  ASSERT_EQ("TEST of ESTEID-SK 2011", manager.getIssuerCN());
}

TEST(PKCS11CardManagerTest, getCertSerialNumber) {
  CK_TOKEN_INFO tokenInfo;
  PKCS11CardManager manager(&tokenInfo, "3082049030820378A00302010202103D1FE64FC8C737D44F83D8516448A1C0300D06092A864886F70D0101050500306C310B300906035504061302454531223020060355040A0C19415320536572746966697473656572696D69736B65736B7573311F301D06035504030C1654455354206F66204553544549442D534B20323031313118301606092A864886F70D0109011609706B6940736B2E6565301E170D3132303431303036353035365A170D3137303333313230353935395A30819A310B3009060355040613024545310F300D060355040A0C06455354454944311A3018060355040B0C116469676974616C207369676E61747572653124302206035504030C1BC5BD41494B4F56534B492C49474F522C33373130313031303032313113301106035504040C0AC5BD41494B4F56534B49310D300B060355042A0C0449474F52311430120603550405130B33373130313031303032313081A0300D06092A864886F70D010101050003818E0030818A02818100B10DDD16CF6A1766422EECCAC4A503A1574E230861684F85AC64FCA4C1D6FDDB80A99EADAC53012B3DD7CC8C67AE0F5D6230F501FD54433E0A7586303AC50B2E1BB193A8BA9E3E6432D48AF69573DF03C63DA85EB2320915E652436588C0DE9E869FE59F1D7313C8E6B2881CE32879CDACF49764D1A697ED4BCF221429ABA8B3020400D4F075A38201803082017C30090603551D1304023000300E0603551D0F0101FF0404030206403081990603551D2004819130818E30818B060A2B06010401CE1F030101307D305806082B06010505070202304C1E4A00410069006E0075006C0074002000740065007300740069006D006900730065006B0073002E0020004F006E006C007900200066006F0072002000740065007300740069006E0067002E302106082B060105050702011615687474703A2F2F7777772E736B2E65652F6370732F30220603551D11041B3019811769676F722E7A61696B6F76736B694065657374692E6565301D0603551D0E0416041494F72921E471EA01140CAC145348790E81052904301806082B06010505070103040C300A3008060604008E460101301F0603551D2304183016801441B6FEC5B1B1B453138CFAFA62D0346D6D22340A30450603551D1F043E303C303AA038A0368634687474703A2F2F7777772E736B2E65652F7265706F7369746F72792F63726C732F746573745F657374656964323031312E63726C300D06092A864886F70D01010505000382010100BF607220FD9FBF806DD2D3190BEB0549A2988C39F8086E50C10D6345B3CCA878E8EABD9152AB4D06CA66A56EBDBA69B5B378A42DCEDBD73CEED47E4A59789B982D743395A58A71CDCEE21EAC050561A15DB8CE16D465A73FB32C91FA680383ADFA95E48515C84A3A6D05A6A4A7EB7DB5DB68D76F5CD7E238C866A2BF7FA5269FA2277BA8C716F20DA1A147D2A79677FE1F8CDFAEA856FADCA99988C8EF1BC381D62F540B5196F6EFD45CD0EBB2F52DE8B8CF69F33EFE70C894BD40A634ABA3A9F5792EDC3A73003335BC7C7FF7F8F429A08138C57B62E2E306AF6E74213232691E0117FC646CEAEDEE1177C5807795A0599A540E654ECD31122D9B1FE248B004");
  ASSERT_EQ("3D1FE64FC8C737D44F83D8516448A1C0", manager.getCertSerialNumber());
}

TEST(PKCS11CardManagerTest, getValidFrom) {
  CK_TOKEN_INFO tokenInfo;
  PKCS11CardManager manager(&tokenInfo, "3082049030820378A00302010202103D1FE64FC8C737D44F83D8516448A1C0300D06092A864886F70D0101050500306C310B300906035504061302454531223020060355040A0C19415320536572746966697473656572696D69736B65736B7573311F301D06035504030C1654455354206F66204553544549442D534B20323031313118301606092A864886F70D0109011609706B6940736B2E6565301E170D3132303431303036353035365A170D3137303333313230353935395A30819A310B3009060355040613024545310F300D060355040A0C06455354454944311A3018060355040B0C116469676974616C207369676E61747572653124302206035504030C1BC5BD41494B4F56534B492C49474F522C33373130313031303032313113301106035504040C0AC5BD41494B4F56534B49310D300B060355042A0C0449474F52311430120603550405130B33373130313031303032313081A0300D06092A864886F70D010101050003818E0030818A02818100B10DDD16CF6A1766422EECCAC4A503A1574E230861684F85AC64FCA4C1D6FDDB80A99EADAC53012B3DD7CC8C67AE0F5D6230F501FD54433E0A7586303AC50B2E1BB193A8BA9E3E6432D48AF69573DF03C63DA85EB2320915E652436588C0DE9E869FE59F1D7313C8E6B2881CE32879CDACF49764D1A697ED4BCF221429ABA8B3020400D4F075A38201803082017C30090603551D1304023000300E0603551D0F0101FF0404030206403081990603551D2004819130818E30818B060A2B06010401CE1F030101307D305806082B06010505070202304C1E4A00410069006E0075006C0074002000740065007300740069006D006900730065006B0073002E0020004F006E006C007900200066006F0072002000740065007300740069006E0067002E302106082B060105050702011615687474703A2F2F7777772E736B2E65652F6370732F30220603551D11041B3019811769676F722E7A61696B6F76736B694065657374692E6565301D0603551D0E0416041494F72921E471EA01140CAC145348790E81052904301806082B06010505070103040C300A3008060604008E460101301F0603551D2304183016801441B6FEC5B1B1B453138CFAFA62D0346D6D22340A30450603551D1F043E303C303AA038A0368634687474703A2F2F7777772E736B2E65652F7265706F7369746F72792F63726C732F746573745F657374656964323031312E63726C300D06092A864886F70D01010505000382010100BF607220FD9FBF806DD2D3190BEB0549A2988C39F8086E50C10D6345B3CCA878E8EABD9152AB4D06CA66A56EBDBA69B5B378A42DCEDBD73CEED47E4A59789B982D743395A58A71CDCEE21EAC050561A15DB8CE16D465A73FB32C91FA680383ADFA95E48515C84A3A6D05A6A4A7EB7DB5DB68D76F5CD7E238C866A2BF7FA5269FA2277BA8C716F20DA1A147D2A79677FE1F8CDFAEA856FADCA99988C8EF1BC381D62F540B5196F6EFD45CD0EBB2F52DE8B8CF69F33EFE70C894BD40A634ABA3A9F5792EDC3A73003335BC7C7FF7F8F429A08138C57B62E2E306AF6E74213232691E0117FC646CEAEDEE1177C5807795A0599A540E654ECD31122D9B1FE248B004");
  ASSERT_EQ(1334091599, manager.getValidFrom());
}

TEST(PKCS11CardManagerTest, getValidTo) {
  CK_TOKEN_INFO tokenInfo;
  PKCS11CardManager manager(&tokenInfo, "3082049030820378A00302010202103D1FE64FC8C737D44F83D8516448A1C0300D06092A864886F70D0101050500306C310B300906035504061302454531223020060355040A0C19415320536572746966697473656572696D69736B65736B7573311F301D06035504030C1654455354206F66204553544549442D534B20323031313118301606092A864886F70D0109011609706B6940736B2E6565301E170D3132303431303036353035365A170D3137303333313230353935395A30819A310B3009060355040613024545310F300D060355040A0C06455354454944311A3018060355040B0C116469676974616C207369676E61747572653124302206035504030C1BC5BD41494B4F56534B492C49474F522C33373130313031303032313113301106035504040C0AC5BD41494B4F56534B49310D300B060355042A0C0449474F52311430120603550405130B33373130313031303032313081A0300D06092A864886F70D010101050003818E0030818A02818100B10DDD16CF6A1766422EECCAC4A503A1574E230861684F85AC64FCA4C1D6FDDB80A99EADAC53012B3DD7CC8C67AE0F5D6230F501FD54433E0A7586303AC50B2E1BB193A8BA9E3E6432D48AF69573DF03C63DA85EB2320915E652436588C0DE9E869FE59F1D7313C8E6B2881CE32879CDACF49764D1A697ED4BCF221429ABA8B3020400D4F075A38201803082017C30090603551D1304023000300E0603551D0F0101FF0404030206403081990603551D2004819130818E30818B060A2B06010401CE1F030101307D305806082B06010505070202304C1E4A00410069006E0075006C0074002000740065007300740069006D006900730065006B0073002E0020004F006E006C007900200066006F0072002000740065007300740069006E0067002E302106082B060105050702011615687474703A2F2F7777772E736B2E65652F6370732F30220603551D11041B3019811769676F722E7A61696B6F76736B694065657374692E6565301D0603551D0E0416041494F72921E471EA01140CAC145348790E81052904301806082B06010505070103040C300A3008060604008E460101301F0603551D2304183016801441B6FEC5B1B1B453138CFAFA62D0346D6D22340A30450603551D1F043E303C303AA038A0368634687474703A2F2F7777772E736B2E65652F7265706F7369746F72792F63726C732F746573745F657374656964323031312E63726C300D06092A864886F70D01010505000382010100BF607220FD9FBF806DD2D3190BEB0549A2988C39F8086E50C10D6345B3CCA878E8EABD9152AB4D06CA66A56EBDBA69B5B378A42DCEDBD73CEED47E4A59789B982D743395A58A71CDCEE21EAC050561A15DB8CE16D465A73FB32C91FA680383ADFA95E48515C84A3A6D05A6A4A7EB7DB5DB68D76F5CD7E238C866A2BF7FA5269FA2277BA8C716F20DA1A147D2A79677FE1F8CDFAEA856FADCA99988C8EF1BC381D62F540B5196F6EFD45CD0EBB2F52DE8B8CF69F33EFE70C894BD40A634ABA3A9F5792EDC3A73003335BC7C7FF7F8F429A08138C57B62E2E306AF6E74213232691E0117FC646CEAEDEE1177C5807795A0599A540E654ECD31122D9B1FE248B004");
  ASSERT_EQ(1490993999, manager.getValidTo());
}

TEST(PKCS11CardManagerTest, PIN2RetryCount_3RetriesLeft) {
  CK_TOKEN_INFO tokenInfo;
  tokenInfo.flags = 0;
  PKCS11CardManager manager(&tokenInfo, "3082049030820378A00302010202103D1FE64FC8C737D44F83D8516448A1C0300D06092A864886F70D0101050500306C310B300906035504061302454531223020060355040A0C19415320536572746966697473656572696D69736B65736B7573311F301D06035504030C1654455354206F66204553544549442D534B20323031313118301606092A864886F70D0109011609706B6940736B2E6565301E170D3132303431303036353035365A170D3137303333313230353935395A30819A310B3009060355040613024545310F300D060355040A0C06455354454944311A3018060355040B0C116469676974616C207369676E61747572653124302206035504030C1BC5BD41494B4F56534B492C49474F522C33373130313031303032313113301106035504040C0AC5BD41494B4F56534B49310D300B060355042A0C0449474F52311430120603550405130B33373130313031303032313081A0300D06092A864886F70D010101050003818E0030818A02818100B10DDD16CF6A1766422EECCAC4A503A1574E230861684F85AC64FCA4C1D6FDDB80A99EADAC53012B3DD7CC8C67AE0F5D6230F501FD54433E0A7586303AC50B2E1BB193A8BA9E3E6432D48AF69573DF03C63DA85EB2320915E652436588C0DE9E869FE59F1D7313C8E6B2881CE32879CDACF49764D1A697ED4BCF221429ABA8B3020400D4F075A38201803082017C30090603551D1304023000300E0603551D0F0101FF0404030206403081990603551D2004819130818E30818B060A2B06010401CE1F030101307D305806082B06010505070202304C1E4A00410069006E0075006C0074002000740065007300740069006D006900730065006B0073002E0020004F006E006C007900200066006F0072002000740065007300740069006E0067002E302106082B060105050702011615687474703A2F2F7777772E736B2E65652F6370732F30220603551D11041B3019811769676F722E7A61696B6F76736B694065657374692E6565301D0603551D0E0416041494F72921E471EA01140CAC145348790E81052904301806082B06010505070103040C300A3008060604008E460101301F0603551D2304183016801441B6FEC5B1B1B453138CFAFA62D0346D6D22340A30450603551D1F043E303C303AA038A0368634687474703A2F2F7777772E736B2E65652F7265706F7369746F72792F63726C732F746573745F657374656964323031312E63726C300D06092A864886F70D01010505000382010100BF607220FD9FBF806DD2D3190BEB0549A2988C39F8086E50C10D6345B3CCA878E8EABD9152AB4D06CA66A56EBDBA69B5B378A42DCEDBD73CEED47E4A59789B982D743395A58A71CDCEE21EAC050561A15DB8CE16D465A73FB32C91FA680383ADFA95E48515C84A3A6D05A6A4A7EB7DB5DB68D76F5CD7E238C866A2BF7FA5269FA2277BA8C716F20DA1A147D2A79677FE1F8CDFAEA856FADCA99988C8EF1BC381D62F540B5196F6EFD45CD0EBB2F52DE8B8CF69F33EFE70C894BD40A634ABA3A9F5792EDC3A73003335BC7C7FF7F8F429A08138C57B62E2E306AF6E74213232691E0117FC646CEAEDEE1177C5807795A0599A540E654ECD31122D9B1FE248B004");
  ASSERT_EQ(3, manager.getPIN2RetryCount());
}

TEST(PKCS11CardManagerTest, PIN2RetryCount_2RetriesLeft) {
  CK_TOKEN_INFO tokenInfo;
  tokenInfo.flags = 0;
  tokenInfo.flags |= CKF_USER_PIN_COUNT_LOW;
  PKCS11CardManager manager(&tokenInfo, "3082049030820378A00302010202103D1FE64FC8C737D44F83D8516448A1C0300D06092A864886F70D0101050500306C310B300906035504061302454531223020060355040A0C19415320536572746966697473656572696D69736B65736B7573311F301D06035504030C1654455354206F66204553544549442D534B20323031313118301606092A864886F70D0109011609706B6940736B2E6565301E170D3132303431303036353035365A170D3137303333313230353935395A30819A310B3009060355040613024545310F300D060355040A0C06455354454944311A3018060355040B0C116469676974616C207369676E61747572653124302206035504030C1BC5BD41494B4F56534B492C49474F522C33373130313031303032313113301106035504040C0AC5BD41494B4F56534B49310D300B060355042A0C0449474F52311430120603550405130B33373130313031303032313081A0300D06092A864886F70D010101050003818E0030818A02818100B10DDD16CF6A1766422EECCAC4A503A1574E230861684F85AC64FCA4C1D6FDDB80A99EADAC53012B3DD7CC8C67AE0F5D6230F501FD54433E0A7586303AC50B2E1BB193A8BA9E3E6432D48AF69573DF03C63DA85EB2320915E652436588C0DE9E869FE59F1D7313C8E6B2881CE32879CDACF49764D1A697ED4BCF221429ABA8B3020400D4F075A38201803082017C30090603551D1304023000300E0603551D0F0101FF0404030206403081990603551D2004819130818E30818B060A2B06010401CE1F030101307D305806082B06010505070202304C1E4A00410069006E0075006C0074002000740065007300740069006D006900730065006B0073002E0020004F006E006C007900200066006F0072002000740065007300740069006E0067002E302106082B060105050702011615687474703A2F2F7777772E736B2E65652F6370732F30220603551D11041B3019811769676F722E7A61696B6F76736B694065657374692E6565301D0603551D0E0416041494F72921E471EA01140CAC145348790E81052904301806082B06010505070103040C300A3008060604008E460101301F0603551D2304183016801441B6FEC5B1B1B453138CFAFA62D0346D6D22340A30450603551D1F043E303C303AA038A0368634687474703A2F2F7777772E736B2E65652F7265706F7369746F72792F63726C732F746573745F657374656964323031312E63726C300D06092A864886F70D01010505000382010100BF607220FD9FBF806DD2D3190BEB0549A2988C39F8086E50C10D6345B3CCA878E8EABD9152AB4D06CA66A56EBDBA69B5B378A42DCEDBD73CEED47E4A59789B982D743395A58A71CDCEE21EAC050561A15DB8CE16D465A73FB32C91FA680383ADFA95E48515C84A3A6D05A6A4A7EB7DB5DB68D76F5CD7E238C866A2BF7FA5269FA2277BA8C716F20DA1A147D2A79677FE1F8CDFAEA856FADCA99988C8EF1BC381D62F540B5196F6EFD45CD0EBB2F52DE8B8CF69F33EFE70C894BD40A634ABA3A9F5792EDC3A73003335BC7C7FF7F8F429A08138C57B62E2E306AF6E74213232691E0117FC646CEAEDEE1177C5807795A0599A540E654ECD31122D9B1FE248B004");
  ASSERT_EQ(2, manager.getPIN2RetryCount());
}

TEST(PKCS11CardManagerTest, PIN2RetryCount_1RetriesLeft) {
  CK_TOKEN_INFO tokenInfo;
  tokenInfo.flags = 0;
  tokenInfo.flags |= CKF_USER_PIN_FINAL_TRY;
  PKCS11CardManager manager(&tokenInfo, "3082049030820378A00302010202103D1FE64FC8C737D44F83D8516448A1C0300D06092A864886F70D0101050500306C310B300906035504061302454531223020060355040A0C19415320536572746966697473656572696D69736B65736B7573311F301D06035504030C1654455354206F66204553544549442D534B20323031313118301606092A864886F70D0109011609706B6940736B2E6565301E170D3132303431303036353035365A170D3137303333313230353935395A30819A310B3009060355040613024545310F300D060355040A0C06455354454944311A3018060355040B0C116469676974616C207369676E61747572653124302206035504030C1BC5BD41494B4F56534B492C49474F522C33373130313031303032313113301106035504040C0AC5BD41494B4F56534B49310D300B060355042A0C0449474F52311430120603550405130B33373130313031303032313081A0300D06092A864886F70D010101050003818E0030818A02818100B10DDD16CF6A1766422EECCAC4A503A1574E230861684F85AC64FCA4C1D6FDDB80A99EADAC53012B3DD7CC8C67AE0F5D6230F501FD54433E0A7586303AC50B2E1BB193A8BA9E3E6432D48AF69573DF03C63DA85EB2320915E652436588C0DE9E869FE59F1D7313C8E6B2881CE32879CDACF49764D1A697ED4BCF221429ABA8B3020400D4F075A38201803082017C30090603551D1304023000300E0603551D0F0101FF0404030206403081990603551D2004819130818E30818B060A2B06010401CE1F030101307D305806082B06010505070202304C1E4A00410069006E0075006C0074002000740065007300740069006D006900730065006B0073002E0020004F006E006C007900200066006F0072002000740065007300740069006E0067002E302106082B060105050702011615687474703A2F2F7777772E736B2E65652F6370732F30220603551D11041B3019811769676F722E7A61696B6F76736B694065657374692E6565301D0603551D0E0416041494F72921E471EA01140CAC145348790E81052904301806082B06010505070103040C300A3008060604008E460101301F0603551D2304183016801441B6FEC5B1B1B453138CFAFA62D0346D6D22340A30450603551D1F043E303C303AA038A0368634687474703A2F2F7777772E736B2E65652F7265706F7369746F72792F63726C732F746573745F657374656964323031312E63726C300D06092A864886F70D01010505000382010100BF607220FD9FBF806DD2D3190BEB0549A2988C39F8086E50C10D6345B3CCA878E8EABD9152AB4D06CA66A56EBDBA69B5B378A42DCEDBD73CEED47E4A59789B982D743395A58A71CDCEE21EAC050561A15DB8CE16D465A73FB32C91FA680383ADFA95E48515C84A3A6D05A6A4A7EB7DB5DB68D76F5CD7E238C866A2BF7FA5269FA2277BA8C716F20DA1A147D2A79677FE1F8CDFAEA856FADCA99988C8EF1BC381D62F540B5196F6EFD45CD0EBB2F52DE8B8CF69F33EFE70C894BD40A634ABA3A9F5792EDC3A73003335BC7C7FF7F8F429A08138C57B62E2E306AF6E74213232691E0117FC646CEAEDEE1177C5807795A0599A540E654ECD31122D9B1FE248B004");
  ASSERT_EQ(1, manager.getPIN2RetryCount());
}

TEST(PKCS11CardManagerTest, PIN2RetryCount_PIN2Blocked) {
  CK_TOKEN_INFO tokenInfo;
  tokenInfo.flags = 0;
  tokenInfo.flags |= CKF_USER_PIN_LOCKED;
  PKCS11CardManager manager(&tokenInfo, "3082049030820378A00302010202103D1FE64FC8C737D44F83D8516448A1C0300D06092A864886F70D0101050500306C310B300906035504061302454531223020060355040A0C19415320536572746966697473656572696D69736B65736B7573311F301D06035504030C1654455354206F66204553544549442D534B20323031313118301606092A864886F70D0109011609706B6940736B2E6565301E170D3132303431303036353035365A170D3137303333313230353935395A30819A310B3009060355040613024545310F300D060355040A0C06455354454944311A3018060355040B0C116469676974616C207369676E61747572653124302206035504030C1BC5BD41494B4F56534B492C49474F522C33373130313031303032313113301106035504040C0AC5BD41494B4F56534B49310D300B060355042A0C0449474F52311430120603550405130B33373130313031303032313081A0300D06092A864886F70D010101050003818E0030818A02818100B10DDD16CF6A1766422EECCAC4A503A1574E230861684F85AC64FCA4C1D6FDDB80A99EADAC53012B3DD7CC8C67AE0F5D6230F501FD54433E0A7586303AC50B2E1BB193A8BA9E3E6432D48AF69573DF03C63DA85EB2320915E652436588C0DE9E869FE59F1D7313C8E6B2881CE32879CDACF49764D1A697ED4BCF221429ABA8B3020400D4F075A38201803082017C30090603551D1304023000300E0603551D0F0101FF0404030206403081990603551D2004819130818E30818B060A2B06010401CE1F030101307D305806082B06010505070202304C1E4A00410069006E0075006C0074002000740065007300740069006D006900730065006B0073002E0020004F006E006C007900200066006F0072002000740065007300740069006E0067002E302106082B060105050702011615687474703A2F2F7777772E736B2E65652F6370732F30220603551D11041B3019811769676F722E7A61696B6F76736B694065657374692E6565301D0603551D0E0416041494F72921E471EA01140CAC145348790E81052904301806082B06010505070103040C300A3008060604008E460101301F0603551D2304183016801441B6FEC5B1B1B453138CFAFA62D0346D6D22340A30450603551D1F043E303C303AA038A0368634687474703A2F2F7777772E736B2E65652F7265706F7369746F72792F63726C732F746573745F657374656964323031312E63726C300D06092A864886F70D01010505000382010100BF607220FD9FBF806DD2D3190BEB0549A2988C39F8086E50C10D6345B3CCA878E8EABD9152AB4D06CA66A56EBDBA69B5B378A42DCEDBD73CEED47E4A59789B982D743395A58A71CDCEE21EAC050561A15DB8CE16D465A73FB32C91FA680383ADFA95E48515C84A3A6D05A6A4A7EB7DB5DB68D76F5CD7E238C866A2BF7FA5269FA2277BA8C716F20DA1A147D2A79677FE1F8CDFAEA856FADCA99988C8EF1BC381D62F540B5196F6EFD45CD0EBB2F52DE8B8CF69F33EFE70C894BD40A634ABA3A9F5792EDC3A73003335BC7C7FF7F8F429A08138C57B62E2E306AF6E74213232691E0117FC646CEAEDEE1177C5807795A0599A540E654ECD31122D9B1FE248B004");
  ASSERT_EQ(0, manager.getPIN2RetryCount());
}

TEST(PKCS11CardManagerTest, readerIsNotPinpad) {
  CK_TOKEN_INFO tokenInfo;
  tokenInfo.flags = 0;
  PKCS11CardManager manager(&tokenInfo, "3082049030820378A00302010202103D1FE64FC8C737D44F83D8516448A1C0300D06092A864886F70D0101050500306C310B300906035504061302454531223020060355040A0C19415320536572746966697473656572696D69736B65736B7573311F301D06035504030C1654455354206F66204553544549442D534B20323031313118301606092A864886F70D0109011609706B6940736B2E6565301E170D3132303431303036353035365A170D3137303333313230353935395A30819A310B3009060355040613024545310F300D060355040A0C06455354454944311A3018060355040B0C116469676974616C207369676E61747572653124302206035504030C1BC5BD41494B4F56534B492C49474F522C33373130313031303032313113301106035504040C0AC5BD41494B4F56534B49310D300B060355042A0C0449474F52311430120603550405130B33373130313031303032313081A0300D06092A864886F70D010101050003818E0030818A02818100B10DDD16CF6A1766422EECCAC4A503A1574E230861684F85AC64FCA4C1D6FDDB80A99EADAC53012B3DD7CC8C67AE0F5D6230F501FD54433E0A7586303AC50B2E1BB193A8BA9E3E6432D48AF69573DF03C63DA85EB2320915E652436588C0DE9E869FE59F1D7313C8E6B2881CE32879CDACF49764D1A697ED4BCF221429ABA8B3020400D4F075A38201803082017C30090603551D1304023000300E0603551D0F0101FF0404030206403081990603551D2004819130818E30818B060A2B06010401CE1F030101307D305806082B06010505070202304C1E4A00410069006E0075006C0074002000740065007300740069006D006900730065006B0073002E0020004F006E006C007900200066006F0072002000740065007300740069006E0067002E302106082B060105050702011615687474703A2F2F7777772E736B2E65652F6370732F30220603551D11041B3019811769676F722E7A61696B6F76736B694065657374692E6565301D0603551D0E0416041494F72921E471EA01140CAC145348790E81052904301806082B06010505070103040C300A3008060604008E460101301F0603551D2304183016801441B6FEC5B1B1B453138CFAFA62D0346D6D22340A30450603551D1F043E303C303AA038A0368634687474703A2F2F7777772E736B2E65652F7265706F7369746F72792F63726C732F746573745F657374656964323031312E63726C300D06092A864886F70D01010505000382010100BF607220FD9FBF806DD2D3190BEB0549A2988C39F8086E50C10D6345B3CCA878E8EABD9152AB4D06CA66A56EBDBA69B5B378A42DCEDBD73CEED47E4A59789B982D743395A58A71CDCEE21EAC050561A15DB8CE16D465A73FB32C91FA680383ADFA95E48515C84A3A6D05A6A4A7EB7DB5DB68D76F5CD7E238C866A2BF7FA5269FA2277BA8C716F20DA1A147D2A79677FE1F8CDFAEA856FADCA99988C8EF1BC381D62F540B5196F6EFD45CD0EBB2F52DE8B8CF69F33EFE70C894BD40A634ABA3A9F5792EDC3A73003335BC7C7FF7F8F429A08138C57B62E2E306AF6E74213232691E0117FC646CEAEDEE1177C5807795A0599A540E654ECD31122D9B1FE248B004");
  ASSERT_EQ(FALSE, manager.isPinpad());  
}

TEST(PKCS11CardManagerTest, readerIsPinpad) {
  CK_TOKEN_INFO tokenInfo;
  tokenInfo.flags = 0;
  tokenInfo.flags |= CKF_PROTECTED_AUTHENTICATION_PATH;
  PKCS11CardManager manager(&tokenInfo, "3082049030820378A00302010202103D1FE64FC8C737D44F83D8516448A1C0300D06092A864886F70D0101050500306C310B300906035504061302454531223020060355040A0C19415320536572746966697473656572696D69736B65736B7573311F301D06035504030C1654455354206F66204553544549442D534B20323031313118301606092A864886F70D0109011609706B6940736B2E6565301E170D3132303431303036353035365A170D3137303333313230353935395A30819A310B3009060355040613024545310F300D060355040A0C06455354454944311A3018060355040B0C116469676974616C207369676E61747572653124302206035504030C1BC5BD41494B4F56534B492C49474F522C33373130313031303032313113301106035504040C0AC5BD41494B4F56534B49310D300B060355042A0C0449474F52311430120603550405130B33373130313031303032313081A0300D06092A864886F70D010101050003818E0030818A02818100B10DDD16CF6A1766422EECCAC4A503A1574E230861684F85AC64FCA4C1D6FDDB80A99EADAC53012B3DD7CC8C67AE0F5D6230F501FD54433E0A7586303AC50B2E1BB193A8BA9E3E6432D48AF69573DF03C63DA85EB2320915E652436588C0DE9E869FE59F1D7313C8E6B2881CE32879CDACF49764D1A697ED4BCF221429ABA8B3020400D4F075A38201803082017C30090603551D1304023000300E0603551D0F0101FF0404030206403081990603551D2004819130818E30818B060A2B06010401CE1F030101307D305806082B06010505070202304C1E4A00410069006E0075006C0074002000740065007300740069006D006900730065006B0073002E0020004F006E006C007900200066006F0072002000740065007300740069006E0067002E302106082B060105050702011615687474703A2F2F7777772E736B2E65652F6370732F30220603551D11041B3019811769676F722E7A61696B6F76736B694065657374692E6565301D0603551D0E0416041494F72921E471EA01140CAC145348790E81052904301806082B06010505070103040C300A3008060604008E460101301F0603551D2304183016801441B6FEC5B1B1B453138CFAFA62D0346D6D22340A30450603551D1F043E303C303AA038A0368634687474703A2F2F7777772E736B2E65652F7265706F7369746F72792F63726C732F746573745F657374656964323031312E63726C300D06092A864886F70D01010505000382010100BF607220FD9FBF806DD2D3190BEB0549A2988C39F8086E50C10D6345B3CCA878E8EABD9152AB4D06CA66A56EBDBA69B5B378A42DCEDBD73CEED47E4A59789B982D743395A58A71CDCEE21EAC050561A15DB8CE16D465A73FB32C91FA680383ADFA95E48515C84A3A6D05A6A4A7EB7DB5DB68D76F5CD7E238C866A2BF7FA5269FA2277BA8C716F20DA1A147D2A79677FE1F8CDFAEA856FADCA99988C8EF1BC381D62F540B5196F6EFD45CD0EBB2F52DE8B8CF69F33EFE70C894BD40A634ABA3A9F5792EDC3A73003335BC7C7FF7F8F429A08138C57B62E2E306AF6E74213232691E0117FC646CEAEDEE1177C5807795A0599A540E654ECD31122D9B1FE248B004");
  ASSERT_EQ(true, manager.isPinpad());  
}
