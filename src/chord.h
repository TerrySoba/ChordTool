#ifndef _CHORD_H
#define _CHORD_H

#include "note.h"

#include <string>
#include <vector>

enum class ChordType {
    Major, Minor, Dominant7, Major7, Minor7,
};


class Chord {
public:
    Chord(Note root, ChordType type);

    std::vector<Note> getNotes() const;

    std::string toString() const;

private:
    std::vector<Note> m_notes;
};


#endif
