#include "chord.h"

typedef int Interval;

#include <map>
#include <vector>

struct ChordTypeAttributes {
    std::string name;
    std::vector<Interval> intervals;
};

std::map<ChordType, ChordTypeAttributes> chordTypes = {
    {ChordType::Major, {"Major", {0, 4, 7}}},
    {ChordType::Minor, {"Minor", {0, 3, 7}}},
    {ChordType::Dominant7, {"Dominant7", {0, 4, 7, 10}}},
    {ChordType::Major7, {"Major7", {0, 4, 7, 11}}},
    {ChordType::Minor7, {"Minor7", {0, 3, 7, 10}}},
};

std::vector<ChordType> getChordTypes()
{
    std::vector<ChordType> types;
    for (const auto& pair : chordTypes) {
        types.push_back(pair.first);
    }
    return types;
}

std::string chordTypeToString(ChordType type)
{
    return chordTypes.at(type).name;
}

Chord::Chord(Note root, ChordType type)
{
    for (Interval interval : chordTypes.at(type).intervals) {
        m_notes.push_back(root + interval);
    }
}

std::vector<Note> Chord::getNotes() const
{
    return m_notes;
}

std::string Chord::toString() const
{
    std::string str = "";
    for (const Note& note : m_notes) {
        str += note.toString() + " ";
    }
    return str.substr(0, str.size() - 1);
}
