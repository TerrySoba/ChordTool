#include "doctest.h"

#include "chord.h"

#include <stdexcept>

TEST_CASE("Chord tests")
{
    Chord chord(Note(NoteValue::C, 2), ChordType::Major);
    std::vector<Note> notes = chord.getNotes();
    REQUIRE(notes.size() == 3);
    REQUIRE(notes[0].getNote() == NoteValue::C);
    REQUIRE(notes[0].getOctave() == 2);
    REQUIRE(notes[1].getNote() == NoteValue::E);
    REQUIRE(notes[1].getOctave() == 2);
    REQUIRE(notes[2].getNote() == NoteValue::G);
    REQUIRE(notes[2].getOctave() == 2);


    chord = Chord(Note(NoteValue::C, 3), ChordType::Minor);
    notes = chord.getNotes();
    REQUIRE(notes.size() == 3);
    REQUIRE(notes[0].getNote() == NoteValue::C);
    REQUIRE(notes[0].getOctave() == 3);
    REQUIRE(notes[1].getNote() == NoteValue::Eb);
    REQUIRE(notes[1].getOctave() == 3);
    REQUIRE(notes[2].getNote() == NoteValue::G);
    REQUIRE(notes[2].getOctave() == 3);


    chord = Chord(Note(NoteValue::A, 3), ChordType::Minor);
    notes = chord.getNotes();
    REQUIRE(notes.size() == 3);
    REQUIRE(notes[0].getNote() == NoteValue::A);
    REQUIRE(notes[0].getOctave() == 3);
    REQUIRE(notes[1].getNote() == NoteValue::C);
    REQUIRE(notes[1].getOctave() == 4);
    REQUIRE(notes[2].getNote() == NoteValue::E);
    REQUIRE(notes[2].getOctave() == 4);
}


TEST_CASE("Chord toString tests")
{
    Chord chord(Note(NoteValue::C, 2), ChordType::Major);
    REQUIRE(chord.toString() == "C2 E2 G2");

    chord = Chord(Note(NoteValue::B, 3), ChordType::Minor);
    REQUIRE(chord.toString() == "B3 D4 Gb4");

    chord = Chord(Note(NoteValue::C, 3), ChordType::Dominant7);
    REQUIRE(chord.toString() == "C3 E3 G3 Bb3");
}