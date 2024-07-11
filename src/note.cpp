#include "note.h"

#include <map>
#include <stdexcept>


static const std::map<NoteValue, std::string> noteToStringMap = {
    {NoteValue::C, "C"},
    {NoteValue::Db, "Db"},
    {NoteValue::D, "D"},
    {NoteValue::Eb, "Eb"},
    {NoteValue::E, "E"},
    {NoteValue::F, "F"},
    {NoteValue::Gb, "Gb"},
    {NoteValue::G, "G"},
    {NoteValue::Ab, "Ab"},
    {NoteValue::A, "A"},
    {NoteValue::Bb, "Bb"},
    {NoteValue::B, "B"}
};


std::string noteToString(NoteValue note)
{
    if (noteToStringMap.find(note) == noteToStringMap.end()) {
        throw std::invalid_argument("Invalid note value");
    }
    return noteToStringMap.at(note);
}


NoteValue stringToNote(const std::string& str)
{
    for (const auto& pair : noteToStringMap) {
        if (pair.second == str) {
            return pair.first;
        }
    }
    throw std::invalid_argument("Invalid note string");
}

Note::Note(NoteValue note, int octave)
    : m_note(note), m_octave(octave)
{
}

NoteValue Note::getNote() const
{
    return m_note;
}

uint8_t Note::getOctave() const
{
    return m_octave;
}

Note& Note::operator+=(int halfSteps)
{
    int note = static_cast<int>(m_note) + halfSteps;
    m_note = static_cast<NoteValue>(note % 12);
    m_octave += note / 12;
    return *this;
}

std::string Note::toString() const
{
    return noteToString(m_note) + std::to_string(m_octave);
}

Note Note::fromString(const std::string& str)
{
    // find first digit
    size_t i = 0;
    while (i < str.size() && !std::isdigit(str[i])) {
        i++;
    }

    if (i == str.size()) {
        throw std::invalid_argument("Invalid note string");
    }

    std::string noteStr = str.substr(0, i);
    std::string octaveStr = str.substr(i);

    return Note{stringToNote(noteStr), std::stoi(octaveStr)};
}

Note operator+(const Note& note, int halfSteps)
{
    Note result = note;
    result += halfSteps;
    return result;
}