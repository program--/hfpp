#include "hfpp/detail/catchment/fwd.hpp"
#include <doctest/doctest.h>

#include <hfpp/fabric.hpp>

#include <hfpp/catchment.hpp>

SCENARIO("Creating a hydrofabric")
{
    hf::fabric& hydrofabric = hf::fabric::instance();

    GIVEN("a hydrofabric dataset")
    {
        hf::catchment cat_1 =
          hf::factory::catchment_builder().with_id("cat-01").get();

        hf::catchment cat_2 = hf::factory::catchment_builder()
                                .with_id("cat-02")
                                .with_upstream(cat_1)
                                .get();

        hf::catchment cat_3 = hf::factory::catchment_builder()
                                .with_id("cat-03")
                                .with_upstream(cat_2)
                                .get();

        hydrofabric.insert(cat_1);
        hydrof
    }
}
