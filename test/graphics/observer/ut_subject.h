#include "../../../src/graphics/observer/subject.h"
#include "../../../src/graphics/observer/observer.h"
#include "../../../src/graphics/real_canvas.h"
#include "./mock_observer.h"

TEST(SubjectTest, testAttachShouldBeCorrect)
{
    Observer *canvas1 = new RealCanvas();
    Observer *canvas2 = new RealCanvas();
    Subject *subject = new Subject();

    subject->attach(canvas1);
    subject->attach(canvas2);

    ASSERT_EQ(2, subject->getObservers().size());
    ASSERT_EQ(canvas1, subject->getObservers().at(0));
    ASSERT_EQ(canvas2, subject->getObservers().at(1));

    delete canvas1;
    delete canvas2;
    delete subject;
}

TEST(SubjectTest, testDetachShouldBeCorrect)
{
    Observer *canvas1 = new RealCanvas();
    Observer *canvas2 = new RealCanvas();
    Observer *canvas3 = new RealCanvas();
    Subject *subject = new Subject();

    subject->attach(canvas1);
    subject->attach(canvas2);
    subject->attach(canvas3);
    subject->detach(canvas2);

    ASSERT_EQ(2, subject->getObservers().size());
    ASSERT_EQ(canvas1, subject->getObservers().at(0));
    ASSERT_EQ(canvas3, subject->getObservers().at(1));

    delete canvas1;
    delete canvas2;
    delete canvas3;
    delete subject;
}

TEST(SubjectTest, testDetachShouldThrowException)
{
    Observer *canvas1 = new RealCanvas();
    Observer *canvas2 = new RealCanvas();
    Observer *canvas3 = new RealCanvas();
    Subject *subject = new Subject();

    subject->attach(canvas1);
    subject->attach(canvas2);
    ASSERT_ANY_THROW(subject->detach(canvas3));

    delete canvas1;
    delete canvas2;
    delete canvas3;
    delete subject;
}

TEST(SubjectTest, testNotifyShouldBeCorrect)
{
    MockObserver *mock1 = new MockObserver();
    MockObserver *mock2 = new MockObserver();
    MockObserver *mock3 = new MockObserver();
    Subject *subject = new Subject();

    subject->attach(mock1);
    subject->attach(mock2);
    subject->attach(mock3);
    subject->notify();

    ASSERT_TRUE(mock1->isUpdated());
    ASSERT_TRUE(mock2->isUpdated());
    ASSERT_TRUE(mock3->isUpdated());

    delete mock1;
    delete mock2;
    delete mock3;
    delete subject;
}