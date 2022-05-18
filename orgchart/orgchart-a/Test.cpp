#include "doctest.h"
#include <iostream>
#include "sources/OrgChart.hpp"

using namespace std;
using namespace ariel;

TEST_CASE("Initialization")
{
    OrgChart organization;
    organization.add_root("liroy")
        .add_sub("liroy", "liav")
        .add_sub("liroy", "lishai")
        .add_sub("liroy", "liren")
        .add_sub("liav", "moshe")
        .add_sub("liav", "yael");

    // └──liroy
    //     ├──liav
    //     │   ├──moshe
    //     │   ├──yael
    //     ├──lishai
    //     ├──liren

    SUBCASE("Checking names")
    {
        CHECK(organization.get_root().name == "liroy");
        CHECK(organization.get_root().children[0]->name == "liav");
        CHECK(organization.get_root().children[1]->name == "lishai");
        CHECK(organization.get_root().children[2]->name == "liren");
        CHECK(organization.get_root().children[0]->children[0]->name == "moshe");
        CHECK(organization.get_root().children[0]->children[1]->name == "yael");
    }

    SUBCASE("overriding root")
    {
        CHECK_NOTHROW(organization.add_root("barak"));
        CHECK_NOTHROW(organization.add_root("arik"));
        CHECK_NOTHROW(organization.add_root("liroy"));
    }
    SUBCASE("Add sub before root")
    {
        OrgChart organization1;
        CHECK_THROWS(organization1.add_sub("liroy", "lishai"));
        CHECK_THROWS(organization1.add_sub("liav", "lishai"));
        CHECK_THROWS(organization1.add_sub("liren", "lishai"));
        CHECK_THROWS(organization1.add_sub("lishai", "liroy"));
    }

    SUBCASE("overriding root after adding sub")
    {
        OrgChart organization2;
        organization2.add_root("liroy")
            .add_sub("liroy", "liav")
            .add_sub("liroy", "lishai")
            .add_sub("liroy", "liren")
            .add_sub("liav", "moshe")
            .add_sub("liav", "yael");
        CHECK(organization2.get_root().name == "liroy");
        CHECK_NOTHROW(organization2.add_root("barak"));
        CHECK(organization2.get_root().name == "barak");
    }

    SUBCASE("Adding an employee with this name to an existing employee")
    {
        OrgChart organization3;
        organization3.add_root("liroy")
            .add_sub("liroy", "liav")
            .add_sub("liroy", "lishai")
            .add_sub("liroy", "liren")
            .add_sub("liav", "moshe")
            .add_sub("liav", "yael");
        CHECK_THROWS(organization3.add_sub("liroy", "liav"));
        CHECK_THROWS(organization3.add_sub("liav", "moshe"));
        CHECK_NOTHROW(organization3.add_sub("lishai", "barak"));
        CHECK_THROWS(organization3.add_sub("lishai", "barak"));
    }
}