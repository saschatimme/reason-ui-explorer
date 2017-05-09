open ReactNative;

let styles =
  StyleSheet.create
    Style.(
      {
        "box": style [backgroundColor "#527FE4", borderColor "#000033", borderWidth 1],
        "zIndex": style [justifyContent `spaceAround, width 100, height 50, marginTop (-10)]
      }
    );

module ViewBorderStyleExample = {
  module Comp = {
    include ReactRe.Component.Stateful;
    let name = "ViewBorderStyleExample";
    type props = unit;
    type state = {showBorder: bool};
    let getInitialState _ => {showBorder: false};
    let handlePress {state} _ => Some {showBorder: not state.showBorder};
    let render {state, updater} =>
      Style.(
        <TouchableWithoutFeedback onPress=(updater handlePress)>
          <View>
            <View
              style=(
                      style [
                        borderWidth 1,
                        borderStyle (
                          if state.showBorder {
                            `dashed
                          } else {
                            `solid
                          }
                        ),
                        padding 5
                      ]
                    )>
              <Text style=(style [fontSize 11])>
                (ReactRe.stringToElement "Dashed border style")
              </Text>
            </View>
            <View
              style=(
                      style [
                        marginTop 5,
                        borderWidth 1,
                        borderRadius 5,
                        borderStyle (
                          if state.showBorder {
                            `dotted
                          } else {
                            `solid
                          }
                        ),
                        padding 5
                      ]
                    )>
              <Text style=(style [fontSize 11])>
                (ReactRe.stringToElement "Dotted border style")
              </Text>
            </View>
          </View>
        </TouchableWithoutFeedback>
      );
  };
  include ReactRe.CreateComponent Comp;
  let createElement = wrapProps ();
};

let title = "<View>";

let description = "Basic building block of all UI, examples that demonstrate some of the many styles available.";

let displayName = "ViewExample";

let examples: list Example.t =
  Style.[
    {
      title: "Background Color",
      description: None,
      render: fun () =>
        <View style=(style [backgroundColor "#527FE4", padding 5])>
          <Text style=(style [fontSize 11])> (ReactRe.stringToElement "Blue background") </Text>
        </View>
    },
    {
      title: "Border",
      description: None,
      render: fun () =>
        <View style=(style [borderColor "#527FE4", borderWidth 5, padding 10])>
          <Text style=(style [fontSize 11])> (ReactRe.stringToElement "5px blue border") </Text>
        </View>
    }, 
    {
     title: "Border Style",
     description: None,
     render: fun () => <ViewBorderStyleExample />
   }
  ];

/*


 class ZIndexExample extends React.Component {
   state = {
     flipped: false
   };

   render() {
     const indices = this.state.flipped ? [-1, 0, 1, 2] : [2, 1, 0, -1];
     return (
       <TouchableWithoutFeedback onPress={this._handlePress}>
         <View>
           <Text style={{paddingBottom: 10}}>Tap to flip sorting order</Text>
           <View style={[
             styles.zIndex,
             {marginTop: 0, backgroundColor: '#E57373', zIndex: indices[0]}
           ]}>
             <Text>ZIndex {indices[0]}</Text>
           </View>
           <View style={[
             styles.zIndex,
             {marginLeft: 50, backgroundColor: '#FFF176', zIndex: indices[1]}
           ]}>
             <Text>ZIndex {indices[1]}</Text>
           </View>
           <View style={[
             styles.zIndex,
             {marginLeft: 100, backgroundColor: '#81C784', zIndex: indices[2]}
           ]}>
             <Text>ZIndex {indices[2]}</Text>
           </View>
           <View style={[
             styles.zIndex,
             {marginLeft: 150, backgroundColor: '#64B5F6', zIndex: indices[3]}
           ]}>
             <Text>ZIndex {indices[3]}</Text>
           </View>
         </View>
       </TouchableWithoutFeedback>
     );
   }

   _handlePress = () => {
     this.setState({flipped: !this.state.flipped});
   };
 }

 exports.title = '<View>';
 exports.description = 'Basic building block of all UI, examples that ' +
   'demonstrate some of the many styles available.';

 exports.displayName = 'ViewExample';
 exports.examples = [
   {
     title: 'Background Color',
     render: function() {
       return (
         <View style={{backgroundColor: '#527FE4', padding: 5}}>
           <Text style={{fontSize: 11}}>
             Blue background
           </Text>
         </View>
       );
     },
   }, {
     title: 'Border',
     render: function() {
       return (
         <View style={{borderColor: '#527FE4', borderWidth: 5, padding: 10}}>
           <Text style={{fontSize: 11}}>5px blue border</Text>
         </View>
       );
     },
   }, {
     title: 'Padding/Margin',
     render: function() {
       return (
         <View style={{borderColor: '#bb0000', borderWidth: 0.5}}>
           <View style={[styles.box, {padding: 5}]}>
             <Text style={{fontSize: 11}}>5px padding</Text>
           </View>
           <View style={[styles.box, {margin: 5}]}>
             <Text style={{fontSize: 11}}>5px margin</Text>
           </View>
           <View style={[styles.box, {margin: 5, padding: 5, alignSelf: 'flex-start'}]}>
             <Text style={{fontSize: 11}}>
               5px margin and padding,
             </Text>
             <Text style={{fontSize: 11}}>
               widthAutonomous=true
             </Text>
           </View>
         </View>
       );
     },
   }, {
     title: 'Border Radius',
     render: function() {
       return (
         <View style={{borderWidth: 0.5, borderRadius: 5, padding: 5}}>
           <Text style={{fontSize: 11}}>
             Too much use of `borderRadius` (especially large radii) on
             anything which is scrolling may result in dropped frames.
             Use sparingly.
           </Text>
         </View>
       );
     },
   }, {
     title: 'Border Style',
     render: function() {
       return <ViewBorderStyleExample />;
     },
   }, {
     title: 'Circle with Border Radius',
     render: function() {
       return (
         <View style={{borderRadius: 10, borderWidth: 1, width: 20, height: 20}} />
       );
     },
   }, {
     title: 'Overflow',
     render: function() {
       return (
         <View style={{flexDirection: 'row'}}>
           <View
             style={{
               width: 95,
               height: 10,
               marginRight: 10,
               marginBottom: 5,
               overflow: 'hidden',
               borderWidth: 0.5,
             }}>
             <View style={{width: 200, height: 20}}>
               <Text>Overflow hidden</Text>
             </View>
           </View>
           <View style={{width: 95, height: 10, marginBottom: 5, borderWidth: 0.5}}>
             <View style={{width: 200, height: 20}}>
               <Text>Overflow visible</Text>
             </View>
           </View>
         </View>
       );
     },
   }, {
     title: 'Opacity',
     render: function() {
       return (
         <View>
           <View style={{opacity: 0}}><Text>Opacity 0</Text></View>
           <View style={{opacity: 0.1}}><Text>Opacity 0.1</Text></View>
           <View style={{opacity: 0.3}}><Text>Opacity 0.3</Text></View>
           <View style={{opacity: 0.5}}><Text>Opacity 0.5</Text></View>
           <View style={{opacity: 0.7}}><Text>Opacity 0.7</Text></View>
           <View style={{opacity: 0.9}}><Text>Opacity 0.9</Text></View>
           <View style={{opacity: 1}}><Text>Opacity 1</Text></View>
         </View>
       );
     },
   }, {
     title: 'ZIndex',
     render: function() {
       return <ZIndexExample />;
     },
   },
 ];*/