open ReactNative;

let styles =
  StyleSheet.create
    Style.(
      {
        "listContainer": style [flex 1.0],
        "row":
          style [
            backgroundColor "white",
            justifyContent `center,
            paddingHorizontal 15,
            paddingVertical 8
          ],
        "rowTitleText": style [fontSize 17, fontWeight `_500],
        "rowDetailText": style [fontSize 15, color "#888888", lineHeight 20],
        "separator":
          style [height StyleSheet.hairlineWidth, backgroundColor "#bbbbbb", marginLeft 15],
        "separatorHighlighted":
          style [height StyleSheet.hairlineWidth, backgroundColor "rgb(217, 217, 217)"]
      }
    );

module UIExplorerExampleList = {
  include ReactRe.Component;
  module List =
    SectionList.CreateComponent {
      include SectionList.Common;
      type item = ExampleList.item;
      let renderItem {item} =>
        <TouchableHighlight onPress=(fun () => ())>
          <View style=styles##row>
            <Text style=styles##rowTitleText>
              ExampleList.(ReactRe.stringToElement item.title)
            </Text>
            <Text style=styles##rowDetailText>
              ExampleList.(ReactRe.stringToElement item.title)
            </Text>
          </View>
        </TouchableHighlight>;
    };
  type props = {onPress: ExampleList.item => unit, components: array ExampleList.item};
  let name = "UIExplorerExampleList";
  let render {props} =>
    <View style=styles##listContainer>
      <List
        sections=[|List.section data::props.components key::"components" ()|]
        keyExtractor=(fun item _ => item.key)
      />
    </View>;
};

include ReactRe.CreateComponent UIExplorerExampleList;

let createElement ::components ::onPress => wrapProps {components, onPress};
