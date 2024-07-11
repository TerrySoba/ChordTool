#include "chord.h"

typedef int Interval;

#include <map>
#include <vector>

std::map<ChordType, std::vector<Interval>> chordTypeIntervals = {
    {ChordType::Major, {0, 4, 7}},
    {ChordType::Minor, {0, 3, 7}},
    {ChordType::Dominant7, {0, 4, 7, 10}},
    {ChordType::Major7, {0, 4, 7, 11}},
    {ChordType::Minor7, {0, 3, 7, 10}},
};


Chord::Chord(Note root, ChordType type)
{
    for (Interval interval : chordTypeIntervals.at(type)) {
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