import React, { useRef } from "react";
import { Alert, StyleSheet, Text, View } from "react-native";
import { Camera, useCameraDevice, useCameraPermission } from "react-native-vision-camera";

const styles = StyleSheet.create({
    container: { flex: 1 },
    camera: { flex: 1 },
});

const CameraView = () => {
    const { hasPermission, requestPermission } = useCameraPermission();
    const device = useCameraDevice("back");
    const cameraRef = useRef<Camera>(null);
    React.useEffect(() => {
        if (!hasPermission) {
            requestPermission().then((status) => {
                if (!status) {
                    Alert.alert("Camera permission denied");
                }
            });
        }
    }, [hasPermission, requestPermission]);
    if (!hasPermission) {
        return (
            <View style={styles.container}>
                <Text>
                    No camera permission
                </Text>
            </View>
        );
    }
    if (!device) {
        return (
            <View style={styles.container}>
                <Text>
                    No camera device
                </Text>
            </View>
        );
    }
    return (
        <View style={styles.container}>
            <Camera
                ref={cameraRef}
                style={styles.camera}
                device={device}
                isActive={true}
            />
        </View>
    );
}

export default CameraView;
