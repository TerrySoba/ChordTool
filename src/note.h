#ifndef _NOTE_H
#define _NOTE_H

#include <string>
#include <cstdint>

enum class NoteValue {
    C, Db, D, Eb, E, F, Gb, G, Ab, A, Bb, B
};

class Note {
public:
    Note(NoteValue note, int octave);
    
    NoteValue getNote() const;
    uint8_t getOctave() const;

    Note& operator+=(int halfSteps);

    std::string toString() const;

    static Note fromString(const std::string& str);

private:
    NoteValue m_note;
    uint8_t m_octave;
};

Note operator+(const Note& note, int halfSteps);

std::string noteToString(NoteValue note);
NoteValue stringToNote(const std::string& str);

#endif