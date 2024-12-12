#include "queue.h"

#include <gtest.h>

#include "queue.h"
#include <gtest.h>

TEST(Queue, can_create_queue_with_default_constructor)
{
    ASSERT_NO_THROW(Queue<int> queue);
}

TEST(Queue, throws_when_create_queue_with_negative_size)
{
    ASSERT_ANY_THROW(Queue<int> queue(-5));
}

TEST(Queue, can_create_queue_with_default_values)
{
    Queue<int> queue(3, 10);

    EXPECT_EQ(queue.size(), 3);
    EXPECT_FALSE(queue.empty());
}

TEST(Queue, can_push_element_to_queue)
{
    Queue<int> queue;

    queue.push(5);

    EXPECT_EQ(queue.size(), 1);
    EXPECT_FALSE(queue.empty());
}

TEST(Queue, can_push_multiple_elements_to_queue)
{
    Queue<int> queue;

    queue.push(5);
    queue.push(10);
    queue.push(15);

    EXPECT_EQ(queue.size(), 3);
}

TEST(Queue, can_pop_element_from_queue)
{
    Queue<int> queue;

    queue.push(5);
    queue.push(10);
    queue.pop();

    EXPECT_EQ(queue.size(), 1);
}

TEST(Queue, can_pop_until_empty)
{
    Queue<int> queue;

    queue.push(5);
    queue.push(10);
    queue.pop();
    queue.pop();

    EXPECT_TRUE(queue.empty());
}

TEST(Queue, throws_when_pop_on_empty_queue)
{
    Queue<int> queue;

    ASSERT_ANY_THROW(queue.pop());
}

TEST(Queue, can_access_top_element)
{
    Queue<int> queue;

    queue.push(5);
    queue.push(10);

    EXPECT_EQ(queue.top(), 10);
}

TEST(Queue, throws_when_access_top_on_empty_queue)
{
    Queue<int> queue;

    ASSERT_ANY_THROW(queue.top());
}

TEST(Queue, empty_returns_true_for_empty_queue)
{
    Queue<int> queue;

    EXPECT_TRUE(queue.empty());
}

TEST(Queue, empty_returns_false_for_nonempty_queue)
{
    Queue<int> queue;

    queue.push(5);

    EXPECT_FALSE(queue.empty());
}

TEST(Queue, size_returns_zero_for_empty_queue)
{
    Queue<int> queue;

    EXPECT_EQ(queue.size(), 0);
}

TEST(Queue, size_returns_correct_value_after_operations)
{
    Queue<int> queue;

    queue.push(5);
    queue.push(10);
    queue.pop();

    EXPECT_EQ(queue.size(), 1);
}

TEST(Queue, behaves_correctly_with_multiple_push_and_pop_operations)
{
    Queue<int> queue;

    queue.push(1);
    queue.push(2);
    queue.push(3);
    queue.pop();
    queue.pop();
    queue.push(4);

    EXPECT_EQ(queue.size(), 2);
    EXPECT_EQ(queue.top(), 4);
}
