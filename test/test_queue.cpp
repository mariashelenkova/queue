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

TEST(Queue, can_push_element_to_queue_size)
{
    Queue<int> queue(10);

    queue.push(5);

    EXPECT_EQ(queue.size(), 1);
}

TEST(Queue, can_push_element_to_queue_empty)
{
    Queue<int> queue(10);

    queue.push(5);

    EXPECT_FALSE(queue.empty());
}

TEST(Queue, can_push_multiple_elements_to_queue)
{
    Queue<int> queue(10);

    queue.push(5);
    queue.push(10);
    queue.push(15);

    EXPECT_EQ(queue.size(), 3);
}

TEST(Queue, can_pop_element_from_queue)
{
    Queue<int> queue(10);

    queue.push(5);
    queue.push(10);
    queue.pop();

    EXPECT_EQ(queue.size(), 1);
}

TEST(Queue, can_pop_until_empty)
{
    Queue<int> queue(10);

    queue.push(5);
    queue.push(10);
    queue.pop();
    queue.pop();

    EXPECT_TRUE(queue.empty());
}

TEST(Queue, throws_when_pop_on_empty_queue)
{
    Queue<int> queue(10);

    ASSERT_ANY_THROW(queue.pop());
}

TEST(Queue, throws_when_access_top_on_empty_queue)
{
    Queue<int> queue(10);

    ASSERT_ANY_THROW(queue.top());
}

TEST(Queue, empty_returns_true_for_empty_queue)
{
    Queue<int> queue(10);

    EXPECT_TRUE(queue.empty());
}

TEST(Queue, empty_returns_false_for_nonempty_queue)
{
    Queue<int> queue(10);

    queue.push(5);

    EXPECT_FALSE(queue.empty());
}

TEST(Queue, size_returns_zero_for_empty_queue)
{
    Queue<int> queue(10);

    EXPECT_EQ(queue.size(), 0);
}

TEST(Queue, size_returns_correct_value_after_operations)
{
    Queue<int> queue(10);

    queue.push(5);
    queue.push(10);
    queue.pop();

    EXPECT_EQ(queue.size(), 1);
}

TEST(Queue, behaves_correctly_with_multiple_push_and_pop_operations_size)
{
    Queue<int> queue(10);

    queue.push(1);
    queue.push(2);
    queue.push(3);
    queue.pop();
    queue.pop();
    queue.push(4);

    EXPECT_EQ(queue.size(), 2);
}

TEST(Queue, top_returns_first_element_in_queue)
{
    Queue<int> queue(10);

    queue.push(5);
    queue.push(10);

    EXPECT_EQ(queue.top(), 5);
}

TEST(Queue, top_updates_correctly_after_pop)
{
    Queue<int> queue(10);

    queue.push(5);
    queue.push(10);
    queue.pop();

    EXPECT_EQ(queue.top(), 10);
}

TEST(Queue, works_correctly_with_circular_buffer_top)
{
    Queue<int> queue(3);

    queue.push(1);
    queue.push(2);
    queue.push(3);
    queue.pop();
    queue.push(4);

    EXPECT_EQ(queue.top(), 2);
}

TEST(Queue, works_correctly_with_circular_buffer_size)
{
    Queue<int> queue(3);

    queue.push(1);
    queue.push(2);
    queue.push(3);
    queue.pop();
    queue.push(4);

    EXPECT_EQ(queue.size(), 3);
}

TEST(Queue, can_increase_capacity_when_full_size)
{
    Queue<int> queue(3);

    queue.push(1);
    queue.push(2);
    queue.push(3);

    EXPECT_EQ(queue.size(), 3);
}

TEST(Queue, can_increase_capacity_when_full_top)
{
    Queue<int> queue(3);

    queue.push(1);
    queue.push(2);
    queue.push(3);
    queue.push(4);

    EXPECT_EQ(queue.top(), 1);
}

TEST(Queue, can_push_elements_after_resizing)
{
    Queue<int> queue(2);

    queue.push(1);
    queue.push(2);

    EXPECT_EQ(queue.size(), 2);
}

TEST(Queue, can_push_elements_after_resizing_size)
{
    Queue<int> queue(2);

    queue.push(1);
    queue.push(2);
    queue.push(3);
    queue.push(4);

    EXPECT_EQ(queue.size(), 4);
}

TEST(Queue, can_push_elements_after_resizing_top)
{
    Queue<int> queue(2);

    queue.push(1);
    queue.push(2);
    queue.push(3);
    queue.push(4);

    EXPECT_EQ(queue.top(), 1);
}

TEST(Queue, can_pop_elements_after_resizing_size)
{
    Queue<int> queue(3);

    queue.push(1);
    queue.push(2);
    queue.push(3);

    queue.push(4);

    queue.pop();

    EXPECT_EQ(queue.size(), 3);
}

TEST(Queue, can_pop_elements_after_resizing_top)
{
    Queue<int> queue(3);

    queue.push(1);
    queue.push(2);
    queue.push(3);

    queue.push(4);

    queue.pop();

    EXPECT_EQ(queue.top(), 2);
}
TEST(Queue, can_handle_multiple_resizes_size)
{
    Queue<int> queue(2);

    for (int i = 1; i <= 10; ++i)
    {
        queue.push(i);
        EXPECT_EQ(queue.size(), i);
    }
}

TEST(Queue, can_push_elements_with_wrap_around)
{
    Queue<int> queue(3);

    queue.push(1);
    queue.push(2);
    queue.push(3);

    queue.pop();

    queue.push(4);

    EXPECT_EQ(queue.top(), 2);
}

TEST(Queue, can_push_to_empty_queue_size)
{
    Queue<int> queue(2);
    queue.push(1);

    EXPECT_EQ(queue.size(), 1);
}

TEST(Queue, can_push_to_empty_queue_top)
{
    Queue<int> queue(2);
    queue.push(1);

    EXPECT_EQ(queue.top(), 1);
}

TEST(Queue, can_push_multiple_elements)
{
    Queue<int> queue(3);

    queue.push(1);
    queue.push(2);
    queue.push(3);

    EXPECT_EQ(queue.size(), 3);
}

TEST(Queue, can_push_elements_after_pop_size)
{
    Queue<int> queue(3);

    queue.push(1);
    queue.push(2);
    queue.pop();

    queue.push(3);
    queue.push(4);

    EXPECT_EQ(queue.size(), 3);
}

TEST(Queue, can_push_elements_after_pop_top)
{
    Queue<int> queue(3);

    queue.push(1);
    queue.push(2);
    queue.pop();

    queue.push(3);
    queue.push(4);

    EXPECT_EQ(queue.top(), 2);
}