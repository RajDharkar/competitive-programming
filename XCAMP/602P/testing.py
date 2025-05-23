import re

def count_syllables_in_word(word):
    word = word.lower()
    word = re.sub(r'[^a-z]', '', word)
    if len(word) == 0:
        return 0

    vowels = 'aeiouy'
    num_vowels = 0
    prev_char_was_vowel = False

    for char in word:
        if char in vowels:
            if not prev_char_was_vowel:
                num_vowels += 1
                prev_char_was_vowel = True
        else:
            prev_char_was_vowel = False

    if word.endswith('e') and num_vowels > 1:
        num_vowels -= 1

    return max(1, num_vowels)

def save_syllables_to_file(text, filename):
    words = re.findall(r'\b\w+\b', text)
    with open(filename, 'w') as f:
        for word in words:
            syllables = count_syllables_in_word(word)
            f.write(f"{word}: {syllables}\n")

excerpt_start = """
Five score years ago, a great American, in whose symbolic shadow we stand,
signed the Emancipation Proclamation.  This momentous decree came as a great
beacon light of hope to millions of Negro slaves who had been seared in the
flames of withering injustice.  It came as a joyous daybreak to end the long
night of captivity.

But one hundred years later, we must face the tragic fact that the Negro is
still not free.  One hundred years later, the life of the Negro is still
sadly crippled by the manacles of segregation and the chains of
discriminaton.  One hundred years later, the Negro lives on a lonely island
of poverty in the midst of a vast ocean of material prosperity.  One hundred
years later, the Negro still languishes in the corners of American society
and finds himself an exile in his own land.  So we have come here today to
dramatize an appalling condition.

In a sense we have come to our nation's capital to cash a check.  When the
architects of our republic wrote the magnificent words of the Constitution
and the Declaration of Independence, they were signing a promissory note to
which every American was to fall heir.  This note was a promise that all men
would be guaranteed the unalienable rights of life, liberty, and the pursuit
of happiness.

It is obvious today that America has defaulted on this promissory note
insofar as her citizens of color are concerned.  Instead of honoring this
sacred obligation, America has given the Negro people a bad check:  a check
which has come back marked "insufficient funds."  But we refuse to believe
that the bank of justice is bankrupt.  We refuse to believe that there are
insufficient funds in the great vaults of opportunity of this nation.  So we
have come to cash this check - a check that will give us upon demand the
riches of freedom and the security of justice.

We have also come to this hallowed spot to remind America the fierce urgency
of now.  This is not time to engage in the luxury of cooling off or to take
the tranquilizing drug of gradualism.  Now is the time to make real the
promises of democracy.  Now is the time to rise from the dark and desolate
valley of segregation to the sunlit path of racial justice.  Now is the time
to open the doors of opportunity to all of God's children.  Now is the time
to lift our nation from the quicksands of racial injustice to the solid rock
of brotherhood.

It would be fatal for the nation to overlook the urgency of the moment and to
underestimate the determination of the Negro.  This sweltering summer of the
Negro's legitimate discontent will not pass until there is an invigorating
autumn of freedom and equality.  Nineteen sixty-three is not an end, but a
beginning.  Those who hope that the Negro needed to blow off steam and will
now be content will have a rude awakening if the nation returns to business
as usual.  There will be neither rest nor tranquillity in America until the
Negro is granted his citizenship rights.  The whirlwinds of revolt will
continue to shake the foundations of our nation until the bright day of
justice emerges.

But there is something that I must say to my people who stand on the warm
threshold which leads into the palace of justice.  In the process of gaining
our rightful place we must not be guilty of wrongful deeds.  Let us not seek
to satisfy our thirst for freedom by drinking from the cup of bitterness and
hatred.  We must forever conduct our struggle on the high plane of dignity
and discipline.  We must not allow our creative protest to degenerate into
physical violence.  Again and again we must rise to the majestic heights of
meeting physical force with soul force.

The marvelous new militancy which has engulfed the Negro community must not
lead us to a distrust of all white people, for many of our white brothers, as
evidences by their presence here today, have come to realize that their
freedom is inextricably bound to our freedom.   We cannot walk alone.

And as we walk, we must make the pledge that we shall march ahead.  We cannot
turn back.  There are those who are asking the devotees of civil rights,
 "When will you be satisfied?"

We can never be satisfied as long as the Negro is the victim of the
unspeakable horrors of police brutality.

We can never be satisfied as long as our bodies, heavy with fatigue of travel,
cannot gain lodging in the motels of the highways and the cities.

We cannot be satisfied as long as the Negro's basic mobility is from a
smaller ghetto to a larger one.

We can never be satisfied as long as a Negro in Mississippi cannot vote and a
Negro in New York believes he has nothing for which to vote.

No, no, we are not satisfied, and we will not be satisfied until justice
rolls down like waters and righteousness like a mighty stream.

I am not unmindful that some of your have come here out of great trials and
tribulations.  Some of you have come fresh from narrow jail cells.  Some of
you have come from areas where your quest for freedom left you battered by
the storms of persecution and staggered by the winds of police brutality.
You have been the veterans of creative suffering.  Continue to work with the
faith that unearned suffering is redemptive.

Go back to Mississippi, go back to Alabama, go back to South Carolina, go
back to Georgia, go back to Louisiana, go back to the slums and ghettos of
our Northern cities, knowing that somehow this situation can and will be
changed.  Let us not wallow in the valley of despair.

I say to you today, my friends, that in spite of the difficulties and
frustrations of the moment I still have a dream.  It is a dream deeply rooted
in the American dream.

I have a dream that one day this nation will rise up and live out the true
meaning of its creed:  "We hold these truths to be self-evident; that all men
are created equal."

I have a dream that one day on the red hills of Georgia the sons of former
slaves and the sons of former slave owners will be able to sit down together
at the table of brotherhood.

I have a dream that one day even the state of Mississippi, a desert state
sweltering with the heat of injustice and oppression, will be transformed
into an oasis of freedom and justice.

I have a dream that my four little children will one day live in a nation
where they will not be judged by the color of their skin but by the content
of their character.

I have a dream today.

I have a dream that one day the state of Alabama, whose governor's lips are
presently dripping with the words of interposition and nullification, will be
transformed into a situation where little black boys and black girls will be
able to join hands with little white boys and girls and walk together as
sisters and brothers.

I have a dream today.

I have a dream that one day every valley shall be exalted, every hill and
mountain shall be made low, the rough places will be made plain, and the
crooked places will be made straight, and the glory of the Lord shall be
revealed, and all flesh shall see it together.

This is our hope.  This is the faith with which I return to the South.  With
this faith we will be able to hew out of the mountain of despair a stone of
hope.  With this faith we will be able to transform the jangling discords of
our nation into a beautiful symphony of brotherhood.

With this faith we will be able to work together, to pray together, to
struggle together, to go to jail together, to stand up for freedom together,
knowing that we will be free one day.

This will be the day when all of God's children will be able to sing with new
meaning, "My country 'tis of thee, sweet land of liberty, of thee I sing.
Land where my father died, land of the Pilgrims' pride, from every
mountainside, let freedom ring."

And if America is to be a great nation, this must become true.  So let
freedom ring from the prodigious hilltops of New Hampshire.  Let freedom ring
from the mighty mountains of New York.  Let freedom ring from the heightening
Alleghenies of Pennsylvania!

Let freedom ring from the snowcapped Rockies of Colorado!  Let freedom ring
from the curvaceous peaks of California.  But not only that:  let freedom
ring from Stone Mountain of Georgia!  Let freedom ring from Lookout Mountain
of Tennessee!

Let freedom ring from every hill and molehill of Mississippi.  From every
mountainside, let freedom ring.

When we let freedom ring, when we let it ring from every village and every
hamlet, from every state and every city, we will be able to speed up that day
when all of God's children, blank men and white men, Jews and Gentiles,
Protestants and Catholics, will be able to join hands and sing in the words
of the old Negro spiritual, "Free at last!  Free at last!  Thank God Almighty,
we are free at last!"
"""
# Use your long excerpt
# save_syllables_to_file(excerpt_start, "syllable_counts.txt")
# print("Syllable counts saved to syllable_counts.txt.")

def read_counts_from_file(filename):
    counts = {}
    with open(filename, 'r') as file:
        for line in file:
            if ':' in line:
                word, count = line.strip().split(':')
                counts[word.strip().lower()] = int(count.strip())
    return counts
def compare_syllable_files_line_by_line(file1, file2):
    with open(file1, 'r') as f1, open(file2, 'r') as f2:
        lines1 = f1.readlines()
        lines2 = f2.readlines()

    min_len = min(len(lines1), len(lines2))
    for i in range(min_len):
        if i < 20:
            continue
        line1 = lines1[i].strip()
        line2 = lines2[i].strip()

        if line1 != line2:
            print(f"Line {i+1} mismatch:\n  {file1}: {line1}\n  {file2}: {line2}")
            break

    if len(lines1) != len(lines2):
        print("\nFile length mismatch:")
        print(f"{file1} has {len(lines1)} lines")
        print(f"{file2} has {len(lines2)} lines")

# Example usage
compare_syllable_files_line_by_line("my_counts.txt", "syllable_counts.txt")
# Call the function with your filenames
