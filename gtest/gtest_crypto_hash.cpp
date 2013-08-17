// Copyright (c) 2012-2013 Plenluno All rights reserved.

#include <gtest/gtest.h>
#include <libnode/crypto.h>

namespace libj {
namespace node {
namespace crypto {

TEST(GTestCryptoHash, TestCreateHash) {
    ASSERT_TRUE(!!createHash(Hash::MD5));
    ASSERT_TRUE(!!createHash(Hash::SHA1));
    ASSERT_TRUE(!!createHash(Hash::SHA256));
    ASSERT_TRUE(!!createHash(Hash::SHA512));
}

TEST(GTestCryptoHash, TestMD5) {
    Hash::Ptr hash = createHash(Hash::MD5);
    ASSERT_TRUE(hash->digest()->toString(Buffer::BASE64)->equals(
        str("1B2M2Y8AsgTpgAmY7PhCfg==")));
    ASSERT_TRUE(hash->digest()->toString(Buffer::HEX)->equals(
        str("d41d8cd98f00b204e9800998ecf8427e")));

    hash = createHash(Hash::MD5);
    ASSERT_TRUE(hash->update(
        Buffer::create(str("abc"), Buffer::UTF8)));
    ASSERT_TRUE(hash->digest()->toString(Buffer::BASE64)->equals(
        str("kAFQmDzST7DWlj99KOF/cg==")));
    ASSERT_TRUE(hash->digest()->toString(Buffer::HEX)->equals(
        str("900150983cd24fb0d6963f7d28e17f72")));
    ASSERT_FALSE(hash->update(
        Buffer::create(str("123"), Buffer::UTF8)));
}

TEST(GTestCryptoHash, TestSHA1) {
    Hash::Ptr hash = createHash(Hash::SHA1);
    ASSERT_TRUE(hash->digest()->toString(Buffer::BASE64)->equals(
        str("2jmj7l5rSw0yVb/vlWAYkK/YBwk=")));
    ASSERT_TRUE(hash->digest()->toString(Buffer::HEX)->equals(
        str("da39a3ee5e6b4b0d3255bfef95601890afd80709")));

    hash = createHash(Hash::SHA1);
    ASSERT_TRUE(hash->update(
        Buffer::create(str("abc"), Buffer::UTF8)));
    ASSERT_TRUE(hash->digest()->toString(Buffer::BASE64)->equals(
        str("qZk+NkcGgWq6PiVxeFDCbJzQ2J0=")));
    ASSERT_TRUE(hash->digest()->toString(Buffer::HEX)->equals(
        str("a9993e364706816aba3e25717850c26c9cd0d89d")));
    ASSERT_FALSE(hash->update(
        Buffer::create(str("123"), Buffer::UTF8)));
}

}  // namespace crypto
}  // namespace node
}  // namespace libj
