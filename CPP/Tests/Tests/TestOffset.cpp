#include <gtest/gtest.h>
#include "../../Clipper2Lib/clipper.offset.h"

TEST(Clipper2Tests, TestOrientationAfterOffsetting) {
    Clipper2Lib::ClipperOffset co;

    const Clipper2Lib::Path64 input = {
        Clipper2Lib::Point64(0, 0),
        Clipper2Lib::Point64(0, 5),
        Clipper2Lib::Point64(5, 5),
        Clipper2Lib::Point64(5, 0)
    };

    EXPECT_FALSE(Clipper2Lib::IsPositive(input));

    co.AddPath(input, Clipper2Lib::JoinType::Round, Clipper2Lib::EndType::Polygon);
    const auto outputs = co.Execute(1);

    ASSERT_EQ(outputs.size(), 1);
    EXPECT_TRUE(Clipper2Lib::IsPositive(outputs[0]));

}