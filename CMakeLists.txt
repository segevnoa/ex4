cmake_minimum_required(VERSION 3.24)
project(updated_ex4)

set(CMAKE_CXX_STANDARD 14)

include_directories(.)
include_directories(Players)

add_executable(updated_ex4
        inputs/badFormat_test.txt
        inputs/badFormat_test_start_of_file.txt
        inputs/empty.txt
        Players/Player.cpp
        Players/Player.h
        tests/allTen_test_expected.txt
        tests/badPlayerInput_test_expected.txt
        tests/dragonDen_test_expected.txt
        tests/gremlinCave_test_expected.txt
        tests/merchantInput_test_expected.txt
        tests/noMonster_test_expected.txt
        tests/roundLimit_test_expected.txt
        tests/witchLair_test_expected.txt
        Mtmchkin.h
        test.cpp
        utilities.cpp
        utilities.h
        Players/Ninja.cpp
        Players/Ninja.h
        Players/Warrior.cpp
        Players/Warrior.h
        Players/Healer.cpp
        Players/Healer.h
        Cards/Card.cpp
        Cards/Card.h
        Cards/Mana.cpp
        Cards/Mana.h
        Cards/Well.h
        Cards/Well.cpp
        Cards/Barfight.cpp
        Cards/Barfight.h
        Cards/Treasure.cpp
        Cards/Treasure.h
        Cards/Battle.cpp
        Cards/Battle.h
        Cards/Gremlin.h
        Cards/Gremlin.cpp
        Cards/Merchant.cpp
        Cards/Merchant.h
        Cards/Witch.h
        Cards/Witch.cpp
        Cards/Dragon.cpp
        Cards/Dragon.h
        Mtmchkin.cpp
        Exception.h
        CardFactory.h
        CardFactory.cpp
        PlayerFactory.cpp
        PlayerFactory.h main.cpp)
