import { SafeAreaView, StyleSheet } from "react-native";
import CameraView from "./components/CameraView";


const styles = StyleSheet.create({
    container: {
        flex: 1,
        backgroundColor: "#035397",
        alignItems: "center",
        justifyContent: "center"
    }
});


export default function App()
{
    return (
        <SafeAreaView style={styles.container}>
            <CameraView />
        </SafeAreaView>
    );
}
