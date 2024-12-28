import React, { useState } from "react";
import { StyleSheet, Text, View } from "react-native";
import CameraView from "./components/CameraView";


const styles = StyleSheet.create({
    container: {
        flex: 1,
    },
});


export default function App() {
    return (
        <View style={styles.container}>
            <CameraView />
        </View>
    );
}
