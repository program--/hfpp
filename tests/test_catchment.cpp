#include <doctest/doctest.h>

#include <hfpp/catchment.hpp>

SCENARIO("Building a catchment") // NOLINT(readability-*)
{
    hf::factory::catchment_builder builder;

    builder.with_id("cat-01");
    REQUIRE_EQ(builder.peek().id(), "cat-01");
    hf::catchment cat_1 = builder.get();
    builder.reset();

    builder.with_id("cat-02");
    hf::catchment cat_2 = builder.get();
    REQUIRE_EQ(cat_2.id(), "cat-02");
    builder.reset();

    hf::catchment cat_3;
    builder.with_id("cat-03");
    REQUIRE_EQ(builder.peek().id(), "cat-03");

    WHEN("Catchment has downstream")
    {
        builder.with_downstream(cat_1);
        REQUIRE_EQ(builder.peek().downstream().size(), 1);
        CHECK_EQ(builder.peek().downstream().begin()->get().id(), "cat-01");

        AND_WHEN("Catchment has another downstream")
        {
            builder.with_downstream(cat_2);
            REQUIRE_EQ(builder.peek().downstream().size(), 2);
            CHECK_EQ(
              (++builder.peek().downstream().begin())->get().id(), "cat-02"
            );
        }

        // TODO: Ensure invariant
        // cat_3 = builder.get();
        // CHECK_EQ(cat_1.upstream().begin()->get().id(), "cat-03");
    }

    WHEN("Catchment has upstream")
    {
        builder.with_upstream(cat_1);
        REQUIRE_EQ(builder.peek().upstream().size(), 1);
        CHECK_EQ(builder.peek().upstream().begin()->get().id(), "cat-01");

        AND_WHEN("Catchment has another upstream")
        {
            builder.with_upstream(cat_2);
            REQUIRE_EQ(builder.peek().upstream().size(), 2);
            CHECK_EQ(
              (++builder.peek().upstream().begin())->get().id(), "cat-02"
            );
        }
    }

    WHEN("Catchment has upstream and downstream")
    {
        builder.with_upstream(cat_1).with_downstream(cat_2);
        const hf::catchment& ref = builder.peek();
        REQUIRE_EQ(ref.downstream().size(), 1);
        REQUIRE_EQ(ref.upstream().size(), 1);
        CHECK_EQ(ref.upstream().begin()->get().id(), "cat-01");
        CHECK_EQ(ref.downstream().begin()->get().id(), "cat-02");
    }
}
