import { SafeAreaView, Text, StyleSheet } from "react-native";
import CameraView from "./components/CameraView";


const styles = StyleSheet.create({
    container: {
        flex: 1,
        backgroundColor: "#aaa",
        alignItems: "center",
        justifyContent: "center"
    }
});


export default function App()
{
    return (
        <SafeAreaView style={styles.container}>
            <Text>tes</Text>
            {/* <CameraView /> */}
        </SafeAreaView>
    );
}
