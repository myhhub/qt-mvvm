#include "google_test.h"
#include "toy_includes.h"

using namespace ModelView;

//! Testing various toy items generated by toy SampleModel.

class TestToyItem : public ::testing::Test
{
public:
    ~TestToyItem();
};

TestToyItem::~TestToyItem() = default;

//! Toy layer as prodused by toy SampleModel.

TEST_F(TestToyItem, Layer)
{
    ToyItems::SampleModel model;
    auto layer = model.insertNewItem(ToyItems::Constants::LayerType);

    EXPECT_FALSE(layer->data(ItemDataRole::DATA).isValid());
    EXPECT_EQ(layer->displayName(), ToyItems::Constants::LayerType);
}

//! Toy multilayer as produced bo toy SampleModel.

TEST_F(TestToyItem, multiLayer)
{
    ToyItems::SampleModel model;
    auto multiLayer = model.insertNewItem(ToyItems::Constants::MultiLayerType);

    EXPECT_FALSE(multiLayer->data(ItemDataRole::DATA).isValid());
    EXPECT_EQ(multiLayer->displayName(), ToyItems::Constants::MultiLayerType);
}

//! Validates display name

TEST_F(TestToyItem, displayName)
{
    ToyItems::SampleModel model;
    auto multiLayer = model.insertNewItem(ToyItems::Constants::MultiLayerType);

    auto layer0 = model.insertNewItem(ToyItems::Constants::LayerType, multiLayer);
    EXPECT_EQ(layer0->displayName(), "Layer");

    auto layer1 = model.insertNewItem(ToyItems::Constants::LayerType, multiLayer);
    EXPECT_EQ(layer0->displayName(), "Layer0");
    EXPECT_EQ(layer1->displayName(), "Layer1");
}
