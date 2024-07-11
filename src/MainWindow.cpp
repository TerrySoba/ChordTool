#include "MainWindow.h"

#include "chord.h"

static void fillNoteComboBox(QComboBox* comboBox)
{
    comboBox->clear();
    comboBox->addItem("C");
    comboBox->addItem("C#");
    comboBox->addItem("D");
    comboBox->addItem("D#");
    comboBox->addItem("E");
    comboBox->addItem("F");
    comboBox->addItem("F#");
    comboBox->addItem("G");
    comboBox->addItem("G#");
    comboBox->addItem("A");
    comboBox->addItem("A#");
    comboBox->addItem("B");
}

static void fillOctaveComboBox(QComboBox* comboBox)
{
    comboBox->clear();
    comboBox->addItem("0");
    comboBox->addItem("1");
    comboBox->addItem("2");
    comboBox->addItem("3");
    comboBox->addItem("4");
    comboBox->addItem("5");
    comboBox->addItem("6");
    comboBox->addItem("7");
    comboBox->addItem("8");
    comboBox->addItem("9");
}

static void fillChordTypeComboBox(QComboBox* comboBox)
{
    comboBox->clear();
    for (ChordType type : getChordTypes()) {
        comboBox->addItem(chordTypeToString(type).c_str());
    }
}


MainWindow::MainWindow(QWidget* parent)
    : QMainWindow(parent)
{
    m_ui.setupUi(this);

    fillNoteComboBox(m_ui.rootNoteComboBox);
    fillOctaveComboBox(m_ui.octaveComboBox);
    fillChordTypeComboBox(m_ui.chordComboBox);

    connect(m_ui.rootNoteComboBox, SIGNAL(currentIndexChanged(int)), this, SLOT(chordSelectionChanged()));
    connect(m_ui.octaveComboBox, SIGNAL(currentIndexChanged(int)), this, SLOT(chordSelectionChanged()));
    connect(m_ui.chordComboBox, SIGNAL(currentIndexChanged(int)), this, SLOT(chordSelectionChanged()));
    chordSelectionChanged();

    m_ui.inversionComboBox->setEnabled(false);
}

MainWindow::~MainWindow()
{
}

void MainWindow::chordSelectionChanged()
{
    NoteValue root = static_cast<NoteValue>(m_ui.rootNoteComboBox->currentIndex());
    int octave = m_ui.octaveComboBox->currentIndex();
    ChordType type = static_cast<ChordType>(m_ui.chordComboBox->currentIndex());

    Note rootNote(root, octave);

    Chord chord(rootNote, type);
    m_ui.chordOutputTextEdit->setText(chord.toString().c_str());
}
