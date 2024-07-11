#include "doctest.h"

#include "note.h"

#include <stdexcept>

TEST_CASE("Note interval test")
{
    Note note(NoteValue::A, 1);

    CHECK(note.getNote() == NoteValue::A);
    CHECK(note.getOctave() == 1);

    note += 1;
    CHECK(note.getNote() == NoteValue::Bb);
    CHECK(note.getOctave() == 1);

    note += 12;
    CHECK(note.getNote() == NoteValue::Bb);
    CHECK(note.getOctave() == 2);

    note += 1;
    CHECK(note.getNote() == NoteValue::B);
    CHECK(note.getOctave() == 2);

    note += 1;
    CHECK(note.getNote() == NoteValue::C);
    CHECK(note.getOctave() == 3);

    note += 9;
    CHECK(note.getNote() == NoteValue::A);
    CHECK(note.getOctave() == 3);
}


TEST_CASE("Note string test")
{
    CHECK(noteToString(NoteValue::C) == "C");
    CHECK(noteToString(NoteValue::Db) == "Db");
    CHECK(noteToString(NoteValue::D) == "D");
    CHECK(noteToString(NoteValue::Eb) == "Eb");
    CHECK(noteToString(NoteValue::E) == "E");
    CHECK(noteToString(NoteValue::F) == "F");
    CHECK(noteToString(NoteValue::Gb) == "Gb");
    CHECK(noteToString(NoteValue::G) == "G");
    CHECK(noteToString(NoteValue::Ab) == "Ab");
    CHECK(noteToString(NoteValue::A) == "A");
    CHECK(noteToString(NoteValue::Bb) == "Bb");
    CHECK(noteToString(NoteValue::B) == "B");

    CHECK(stringToNote("C") == NoteValue::C);
    CHECK(stringToNote("Db") == NoteValue::Db);
    CHECK(stringToNote("D") == NoteValue::D);
    CHECK(stringToNote("Eb") == NoteValue::Eb);
    CHECK(stringToNote("E") == NoteValue::E);
    CHECK(stringToNote("F") == NoteValue::F);
    CHECK(stringToNote("Gb") == NoteValue::Gb);
    CHECK(stringToNote("G") == NoteValue::G);
    CHECK(stringToNote("Ab") == NoteValue::Ab);
    CHECK(stringToNote("A") == NoteValue::A);
    CHECK(stringToNote("Bb") == NoteValue::Bb);
    CHECK(stringToNote("B") == NoteValue::B);
}


TEST_CASE("Note toString test")
{
    Note note1(NoteValue::C, 1);
    CHECK(note1.toString() == "C1");

    Note note2(NoteValue::Db, 2);
    CHECK(note2.toString() == "Db2");

    Note note3(NoteValue::D, 3);
    CHECK(note3.toString() == "D3");

    Note note4(NoteValue::Eb, 4);
    CHECK(note4.toString() == "Eb4");

    Note note5(NoteValue::E, 5);
    CHECK(note5.toString() == "E5");

    Note note6(NoteValue::F, 6);
    CHECK(note6.toString() == "F6");

    Note note7(NoteValue::Gb, 7);
    CHECK(note7.toString() == "Gb7");

    Note note8(NoteValue::G, 8);
    CHECK(note8.toString() == "G8");

    Note note9(NoteValue::Ab, 9);
    CHECK(note9.toString() == "Ab9");

    Note note10(NoteValue::A, 10);
    CHECK(note10.toString() == "A10");

    Note note11(NoteValue::Bb, 11);
    CHECK(note11.toString() == "Bb11");

    Note note12(NoteValue::B, 12);
    CHECK(note12.toString() == "B12");
}

TEST_CASE("Note fromString test")
{
    CHECK(Note::fromString("C1").getNote() == NoteValue::C);
    CHECK(Note::fromString("Db2").getNote() == NoteValue::Db);
    CHECK(Note::fromString("D3").getNote() == NoteValue::D);
    CHECK(Note::fromString("Eb4").getNote() == NoteValue::Eb);
    CHECK(Note::fromString("E5").getNote() == NoteValue::E);
    CHECK(Note::fromString("F6").getNote() == NoteValue::F);
    CHECK(Note::fromString("Gb7").getNote() == NoteValue::Gb);
    CHECK(Note::fromString("G8").getNote() == NoteValue::G);
    CHECK(Note::fromString("Ab9").getNote() == NoteValue::Ab);
    CHECK(Note::fromString("A10").getNote() == NoteValue::A);
    CHECK(Note::fromString("Bb11").getNote() == NoteValue::Bb);
    CHECK(Note::fromString("B12").getNote() == NoteValue::B);

    CHECK(Note::fromString("C1").getOctave() == 1);
    CHECK(Note::fromString("Db2").getOctave() == 2);
    CHECK(Note::fromString("D3").getOctave() == 3);
    CHECK(Note::fromString("Eb4").getOctave() == 4);
    CHECK(Note::fromString("E5").getOctave() == 5);
    CHECK(Note::fromString("F6").getOctave() == 6);
    CHECK(Note::fromString("Gb7").getOctave() == 7);
    CHECK(Note::fromString("G8").getOctave() == 8);
    CHECK(Note::fromString("Ab9").getOctave() == 9);
    CHECK(Note::fromString("A10").getOctave() == 10);
    CHECK(Note::fromString("Bb11").getOctave() == 11);
    CHECK(Note::fromString("B12").getOctave() == 12);
}

TEST_CASE("Note exception test")
{
    CHECK_THROWS_AS(Note::fromString("C"), std::invalid_argument);
    CHECK_THROWS_AS(Note::fromString("Y"), std::invalid_argument);
    CHECK_THROWS_AS(Note::fromString("1C"), std::invalid_argument);
    CHECK_THROWS_AS(Note::fromString("N7"), std::invalid_argument);
}

