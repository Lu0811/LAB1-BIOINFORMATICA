#include "gtest/gtest.h"
#include "Bioinformatics.h"

class BioinformaticsTest : public ::testing::Test {
protected:
    Bioinformatics bio;
};

// Test para secuencia de ADN
TEST_F(BioinformaticsTest, BTBSCRYR_ADN) {
    std::string seq =
        "tgcaccaaacatgtctaaagctggaaccaaaattactttctttgaagacaaaaactttca"
        "aggccgccactatgacagcgattgcgactgtgcagatttccacatgtacctgagccgctg"
        "caactccatcagagtggaaggaggcacctgggctgtgtatgaaaggcccaattttgctgg"
        "gtacatgtacatcctaccccggggcgagtatcctgagtaccagcactggatgggcctcaa"
        "cgaccgcctcagctcctgcagggctgttcacctgtctagtggaggccagtataagcttca"
        "gatctttgagaaaggggattttaatggtcagatgcatgagaccacggaagactgcccttc"
        "catcatggagcagttccacatgcgggaggtccactcctgtaaggtgctggagggcgcctg"
        "gatcttctatgagctgcccaactaccgaggcaggcagtacctgctggacaagaaggagta"
        "ccggaagcccgtcgactggggtgcagcttccccagctgtccagtctttccgccgcattgt"
        "ggagtgatgatacagatgcggccaaacgctggctggccttgtcatccaaataagcattat"
        "aaataaaacaattggcatgc";
    EXPECT_EQ(bio.identificarCadena(seq), "ADN");
}

// Macro para probar proteínas
#define TEST_PROTEINA(name, seq) \
TEST_F(BioinformaticsTest, name) { \
    std::string secuencia = seq; \
    EXPECT_EQ(bio.identificarCadena(secuencia), "Proteína"); \
    auto aa = bio.obtenerAminoacidos(secuencia.substr(0, 5)); \
    EXPECT_EQ(aa.size(), 5); \
    for (const auto& a : aa) { \
        EXPECT_NE(a, "Desconocido"); \
    } \
}

// Tests para proteínas
TEST_PROTEINA(crab_anapl,
"MDITIHNPLIRRPLFSWLAPSRIFDQIFGEHLQESELLPASPSLSPFLMR"
"SPIFRMPSWLETGLSEMRLEKDKFSVNLDVKHFSPEELKVKVLGDMVEIH"
"GKHEERQDEHGFIAREFNRKYRIPADVDPLTITSSLSLDGVLTVSAPRKQ"
"SDVPERSIPITREEKPAIAGAQRK")

TEST_PROTEINA(crab_bovin,
"MDIAIHHPWIRRPFFPFHSPSRLFDQFFGEHLLESDLFPASTSLSPFYLR"
"PPSFLRAPSWIDTGLSEMRLEKDRFSVNLDVKHFSPEELKVKVLGDVIEV"
"HGKHEERQDEHGFISREFHRKYRIPADVDPLAITSSLSSDGVLTVNGPRK"
"QASGPERTIPITREEKPAVTAAPKK")

TEST_PROTEINA(crab_chick,
"MDITIHNPLVRRPLFSWLTPSRIFDQIFGEHLQESELLPTSPSLSPFLMR"
"SPFFRMPSWLETGLSEMRLEKDKFSVNLDVKHFSPEELKVKVLGDMIEIH"
"GKHEERQDEHGFIAREFSRKYRIPADVDPLTITSSLSLDGVLTVSAPRKQ"
"SDVPERSIPITREEKPAIAGSQRK")

TEST_PROTEINA(crab_human,
"MDIAIHHPWIRRPFFPFHSPSRLFDQFFGEHLLESDLFPTSTSLSPFYLR"
"PPSFLRAPSWFDTGLSEMRLEKDRFSVNLDVKHFSPEELKVKVLGDVIEV"
"HGKHEERQDEHGFISREFHRKYRIPADVDPLTITSSLSSDGVLTVNGPRK"
"QVSGPERTIPITREEKPAVTAAPKK")

TEST_PROTEINA(crab_mesau,
"MDIAIHHPWIRRPFFPFHSPSRLFDQFFGEHLLESDLFSTATSLSPFYLR"
"PPSFLRAPSWIDTGLSEMRMEKDRFSVNLDVKHFSPEELKVKVLGDVVEV"
"HGKHEERQDEHGFISREFHRKYRIPADVDPLTITSSLSSDGVLTVNGPRK"
"QASGPERTIPITREEKPAVTAAPKK")

TEST_PROTEINA(crab_mouse,
"MDIAIHHPWIRRPFFPFHSPSRLFDQFFGEHLLESDLFSTATSLSPFYLR"
"PPSFLRAPSWIDTGLSEMRLEKDRFSVNLDVKHFSPEELKVKVLGDVIEV"
"HGKHEERQDEHGFISREFHRKYRIPADVDPLAITSSLSSDGVLTVNGPRK"
"QVSGPERTIPITREEKPAVAAAPKK")

TEST_PROTEINA(crab_rabit,
"MDIAIHHPWIRRPFFPFHSPSRLFDQFFGEHLLESDLFPTSTSLSPFYLR"
"PPSFLRAPSWIDTGLSEMRLEKDRFSVNLDVKHFSPEELKVKVLGDVIEV"
"HGKHEERQDEHGFISREFHRKYRIPADVDPLTITSSLSSDGVLTVNGPRK"
"QAPGPERTIPITREEKPAVTAAPKK")

TEST_PROTEINA(crab_rat,
"MDIAIHHPWIRRPFFPFHSPSRLFDQFFGEHLLESDLFSTATSLSPFYLR"
"PPSFLRAPSWIDTGLSEMRMEKDRFSVNLDVKHFSPEELKVKVLGDVIEV"
"HGKHEERQDEHGFISREFHRKYRIPADVDPLTITSSLSSDGVLTVNGPRK"
"QASGPERTIPITREEKPAVTAAPKK")

TEST_PROTEINA(crab_squac,
"MDIAIQHPWLRRPLFPSSIFPSRIFDQNFGEHFDPDLFPSFSSMLSPFYW"
"RMGAPMARMPSWAQTGLSELRLDKDKFAIHLDVKHFTPEELRVKILGDFI"
"EVQAQHEERQDEHGYVSREFHRKYKVPAGVDPLVITCSLSADGVLTITGP"
"RKVADVPERSVPISRDEKPAVAGPQQK")
